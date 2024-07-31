#include "data_buffer.h"

void Data_buffer::AddData(const std::string &data,
                          const std::vector<int> &digits) {
  data_ = data;
  digits_container_ = digits;
}

void Data_buffer::Clear() {
  data_.clear();
  digits_container_.clear();
}

const bool Data_buffer::IsClear() const {
  return (data_.empty() && digits_container_.empty());
}

const std::string Data_buffer::GetData() const { return data_; }

const std::vector<int> Data_buffer::GetDigits() const {
  return digits_container_;
}
