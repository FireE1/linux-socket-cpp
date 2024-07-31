#include "core.h"

void Client::Reader() {
  // Reader input buffer
  std::string input;

  // Get input
  std::cout << "Enter data: ";
  std::cin >> input;

  if (input.size() > 64) {
    return;
  }

  // Processed input buffers
  std::vector<std::string> updated_input;
  std::vector<int> odd_digits;

  for (const char input_member : input) {
    // Check for letters
    if (!isdigit(input_member)) {
      return;
    }

    // Save in better place
    updated_input.push_back(std::string{input_member});
  }

  std::sort(updated_input.begin(), updated_input.end());

  // String to save in shared buffer
  std::string input_to_string;
  for (std::string s : updated_input) {
    // Cast to int
    int digit = s[0] - '0';
    if (digit % 2 != 0) {
      input_to_string += s;
      odd_digits.push_back(digit);
    } else {
      input_to_string += "KB";
    }
  }

  buffer_.data_mutex_.lock();                   //  LOCK
                                                //
  buffer_.AddData(input_to_string, odd_digits); // "mutex" operation *
                                                //
  buffer_.data_mutex_.unlock();                 //  UNLOCK

  // Make some rest for reader
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void Client::Sender() {
  // While shared buffer is empty, sender waits
  while (buffer_.IsClear()) {
  }

  buffer_.data_mutex_.lock();                    //  LOCK
                                                 //
  std::cout << "Result: " << buffer_.GetData()   //  "mutex" operation *
            << std::endl;                        //                    *
  std::vector<int> digits = buffer_.GetDigits(); //                    *
  buffer_.Clear();                               //                    *
                                                 //
  buffer_.data_mutex_.unlock();                  //  UNLOCK

  // Get sum of odd digits and cast it to string
  std::string digits_sum =
      std::to_string(std::accumulate(digits.begin(), digits.end(), 0));
  socket_.SendMessage(digits_sum);

  // Make some rest for sender
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void Client::ReaderLoop() {
  while (true) {
    Reader();
  }
}

void Client::SenderLoop() {
  while (true) {
    Sender();
  }
}
