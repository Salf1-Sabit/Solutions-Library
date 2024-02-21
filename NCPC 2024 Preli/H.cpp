// Problem H 
#include <bits/stdc++.h>
using namespace std;

int daysCount[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> dayNames = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
map<string, int> dayNo = {{"Sun", 1}, {"Mon", 2}, {"Tue", 3}, {"Wed", 4}, {"Thu", 5}, {"Fri", 6}, {"Sat", 7}};

bool isLeapYear (int year) {
  if (year % 400 == 0) {
    return true;
  } else if (year % 100 == 0) {
    return false;
  } else if (year % 4 == 0) {
    return true;
  }
  return false;
}

int main () {
  int tt;
  cin >> tt;
  while (tt--) {
  	// Take input
    char ign;
    string dayName;
    int day, month, year;
    cin >> day >> ign >> month >> ign >> year >> dayName;

    // Check leap year
    daysCount[2] = (isLeapYear(year) ? 29 : 28);
		
		// Get the dayName ID from dayNames vector
    int curDayNo = day, dayNameId = -1;
    for (int d = 0; d < 7; ++d) {
      if (dayNames[d] == dayName) {
        dayNameId = d;
        break;
      }
    }
		
		// Figure out the dayNameId for Date "1" of that month
    while (curDayNo > 1) {
      --curDayNo, --dayNameId;
      if (dayNameId == -1) {
        dayNameId = 6;
      }
    }
		
		// Initialize the answer grid with "-" dashes
    vector<vector<string>> grid(5, vector<string>(7, "-"));
    
    // Starting colomn number (colNo) and starting date (val)
    int colNo = dayNo[dayNames[dayNameId]] - 1, val = 1;
		
		// Start filling out the answer grid with corresponding date
    for (int rowNo = 0; rowNo < 5; ++rowNo) { // Run for each row
      while (true) {
      
        // If all dates are filled for the current month then break
        if (val > daysCount[month]) { 
          break;
        }
        
        // Fill the dates and change to string
        grid[rowNo][colNo] = to_string(val++); 
        
        // If we're at the last column just stop
        if (colNo + 1 == 7) { 
          colNo = 0;
          break;
        }
        
        // otherwise go to the last column
        ++colNo; 
      }
    }
		
		// Now, reset the column the the 0th column
    colNo = 0;
    
    /* If there're anymore dates left to fill 
       then start putting them on the 0th row */ 
    while (val <= daysCount[month]) {
      grid[0][colNo++] = to_string(val++);
    }
		
		// Start printing the outputs
    cout << "|---------------------------|\n";
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
    cout << "|---------------------------|\n";
		
    for (int r = 0; r < 5; ++r) {
      for (int c = 0; c < 7; ++c) {
      
      	// If this is the first column just print "|" a bar
        if (c == 0) {
          cout << "|";
        }
        
        if (grid[r][c] == "-") {  
          cout << " " << grid[r][c] << " |"; // put one space to the left and to right (in case of dash)
        } else if (stoi(grid[r][c]) > 9) {
          cout << " " << grid[r][c] << "|"; // put one space to the left only (in case of double digits)
        } else {
          cout << "  " << grid[r][c] << "|"; // put two spaces to the left only (in case of single digit)
        }
      }
      cout << "\n|---------------------------|\n";
    }
    cout << "\n";
  }
  return 0;
}
