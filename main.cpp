#include <string>
#include <iostream>
#include <vector>

std::string format_duration(int seconds) {
  std::vector<std::string> result_array = {};
  std::string result_string = "";
  std::string next_phrase = "";

  std::vector<int> durations = {31536000, 86400, 3600, 1};
  int duration;
  int how_many_durations;
  for (int i = 0; i < 3; i++) {
    duration = durations[i];
    if (seconds > duration) {
      how_many_durations = seconds / duration;
      seconds -= how_many_durations * duration;

      next_phrase = std::to_string(how_many_durations);
      if (i == 0) {
        next_phrase += " year";
      } else if (i == 1) {
        next_phrase += " day";
      } else {
        next_phrase += " hour";
      }
      if (how_many_durations > 1) {
        next_phrase += 's';
      }
      result_array.push_back(next_phrase);
      next_phrase = "";
    } else {
      next_phrase = std::to_string(seconds) + " second";
      if (seconds > 1) {
        next_phrase += 's';
      }
      result_array.push_back(next_phrase);
    }
  }
  // seconds
  if (seconds != 0) {
    next_phrase = std::to_string(seconds) + " second";
    if (seconds > 1) {
      next_phrase += 's';
    }
    result_array.push_back(next_phrase);
  }
  
  for (int i = 0; i < result_array.size(); i++) {
    
  }

  std::cout << seconds << " left" << std::endl;
  for (int i = 0; i < result_array.size(); i++) {
    std::cout << result_array[i] << ' ';
  }
}

int main() {
  format_duration(500000401);
  return 0;
}