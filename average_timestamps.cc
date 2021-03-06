#include <ctime>
#include <iostream>
#include <iomanip>
#include <map>

int main() {
  std::map<time_t, unsigned int> submissions;
  time_t input;

  while (std::cin >> input) {
    if (submissions.count(input) == 1) {
      submissions[input]++;
    } else {
      submissions[input] = 1;
    }
  }

  time_t begin = 1199142000; // 2008-01-01
  time_t end = begin + 24*3600;

  std::map<time_t, unsigned int> day_submissions;
  std::map<time_t, double> avg_submissions;

  for (std::map<time_t, unsigned int>::iterator it(submissions.begin()); it != submissions.end(); begin += 24*3600, end = begin + 24*3600) {
    unsigned int current = 0;
    while (it != submissions.end() && it->first < end) {
      current += it->second;
      ++it;
    }

    day_submissions[begin] = current;
  }

  for (std::map<time_t, unsigned int>::iterator it(day_submissions.begin()); it != day_submissions.end(); ++it) {
    avg_submissions[it->first] = double(it->second)/10.0;
    std::map<time_t, unsigned int>::iterator tmp(it);
    for (int i = 0; i < 5; ++i) {
      if (tmp == day_submissions.begin()) break;
      --tmp;
      avg_submissions[it->first] += double(tmp->second)/10.0;
    }
    tmp = it;
    for (int i = 0; i < 5; ++i) {
      ++tmp;
      if (tmp == day_submissions.end()) break;
      avg_submissions[it->first] += double(tmp->second)/10.0;
    }
  }

  for (std::map<time_t, double>::iterator it(avg_submissions.begin()); it != avg_submissions.end(); ++it) {
    struct tm *date = localtime(&(it->first));
    std::cout << date->tm_year + 1900 << "-" << std::setfill('0') << std::setw(2) << date->tm_mon + 1 << "-" << std::setw(2) << date->tm_mday << " " << it->second << std::endl;
  }
  return 0;
}
