#include <string>
#include <iostream>
#include <vector>

std::string format_duration(int seconds) {
  std::vector<std::string> result_array = {};
  std::string result_string = "";
  std::string next_phrase = "";

  std::vector<int> durations = {31536000, 86400, 3600, 60, 1};
  int duration;
  int how_many_durations;
  for (int i = 0; i < 5; i++) {
    duration = durations[i];
    if (seconds > duration) {
      how_many_durations = seconds / duration;
      seconds -= how_many_durations * duration;

      next_phrase = std::to_string(how_many_durations);
      if (i == 0) {
        next_phrase += " year";
      } else if (i == 1) {
        next_phrase += " day";
      } else if (i == 2) {
        next_phrase += " hour";
      } else if (i == 3) {
        next_phrase += " minute";
      } else {
        next_phrase += " second";
      }
      if (how_many_durations > 1) {
        next_phrase += 's';
      }
      result_array.push_back(next_phrase);
      next_phrase = "";
    }
  }
  
  int result_array_size = result_array.size();
  for (int i = 0; i < result_array_size; i++) {
    result_string += result_array[i];
    if (i + 2 == result_array_size) {
      result_string += " and ";
    }
    if (i + 2 < result_array_size) {
      result_string += ", ";
    }
  }

  std::cout << result_string;
}

int main() {
  format_duration(62);
  return 0;
}