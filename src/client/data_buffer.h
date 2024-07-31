#pragma once

#include <mutex>
#include <string>
#include <vector>

struct Data_buffer {

  void AddData(const std::string &data, const std::vector<int> &digits);

  void Clear();
  const bool IsClear() const;

  const std::string GetData() const;
  const std::vector<int> GetDigits() const;

  std::string data_ = "";
  std::vector<int> digits_container_ = {};
  std::mutex data_mutex_;
};
