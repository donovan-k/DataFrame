#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <map>


using std::string;
using std::map;
using std::vector;
using std::istream;

class DataFrame {
  public:
    /**
     * Constructor for creating a dataframe out of a csv file
    */
    DataFrame(std::string filename, int n_rows=0, bool has_col_names=true) {
      n_rows_ = n_rows;
      filename_ = filename;
      createStringValues(has_col_names);
   }

  map<string, vector<float>> numeric_values_;
  map<string, vector<string>> string_values_;
  vector<string> column_names_;
  int n_rows_;

  private:
    // member variables
    string filename_; // name of csv file

    /**
     * @brief Create a String Values object that maps column names
     * to an array of values
     * (calls csv read row function)
     * 
     */
    void createStringValues(bool has_col_names);

    /** @brief functions are from http://www.zedwood.com/article/cpp-csv-parser
     * used for reading a line from a csv file
     * 
     * @param line specific line of file to read
     * @param delimiter separator between values in line
     * @return vector<string> vector of row values of line
     */
    vector<string> csv_read_row(string &line, char delimiter);

    /**
     * @brief read doc above
     * 
     * @param line specific line of file to read
     * @param delimiter separator between values in line
     * @return vector<string> vector of row values of line
     */
    vector<string> csv_read_row(istream &in, char delimiter);

};