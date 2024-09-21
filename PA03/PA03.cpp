#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
  string first_name;
  string last_name;
  int percentage_grade;  
  char letter_grade;
};

vector<string> split(string line) {
  vector<string> tokens;
  string token;
  char delimiter = ' ';
  size_t start = 0;
  size_t index = line.find(delimiter, start);

  while (index != string::npos) {
    size_t length = index - start;
    tokens.push_back(line.substr(start, length));
    start += length + 1;
    index = line.find(delimiter, start);
  }
  tokens.push_back(line.substr(start));
  return tokens;
}

char calculateGrade(int grade) {
  if (grade >= 90) return 'A';
  if (grade >= 80) return 'B';
  if (grade >= 70) return 'C';
  if (grade >= 60) return 'D';
  return 'F';
}

void highestScore(int highest_score) {	
  cout << highest_score << '\n';
}


vector<Student> getData(ifstream &infile) {
  vector<Student> students;
  string line;
  int x = 0;
  int highest = 0;
  while (getline(infile, line)) {
    vector<string> tokens = split(line);
 
    if (tokens.size() == 3) {
      int grade = stoi(tokens[2]);
      if (grade > highest)
        highest = grade;

      Student student = { tokens[0], tokens[1], grade, calculateGrade(grade) };
      
      students.push_back(student);
    }
    x++;
  } 
  highestScore(highest);
  return students;
}

void writeData(ofstream &outfile, const vector<Student>& students) {
  for (const auto& student : students) {
    outfile << student.first_name << " " << student.last_name << " "
            << student.percentage_grade<< " " << student.letter_grade << '\n';
  } 
}

bool openInputFile(ifstream &infile, const char *filename) {
  if (!infile) {
    cerr << "Error: Could not open input file " << filename << '\n';
    return false;
  }
  return true;
}

bool openOutputFile(ofstream &outfile, const char *filename) {
  if (!outfile) {
    cerr << "Error: Could not open output file " << filename << '\n';
    return false;
  }
  return true;
}

int processFiles(const char *inputFile, const char *outputFile) {
  ifstream infile(inputFile);
  if (!openInputFile(infile, inputFile))
    return 1;
  
  vector<Student> students = getData(infile);
  infile.close();

  ofstream outfile;
  if (!openOutputFile(outfile, outputFile))
    return 1;
  writeData(outfile, students);
  outfile.close();

  return 0;
}

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <input_file>" << " <output_file>" << '\n';
    return 1;
  }

  // first arg should be input file name
  // second arg should be output file name
  return processFiles(argv[1], argv[2]);
}
