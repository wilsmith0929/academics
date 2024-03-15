#include "interface.h"
#include "utilities.h"

int main() {
    begin();

         //this is to test the weekly EFT report 
    string inputFilename = "../text-documents/services.txt";
        // Generate the weekly EFT report
    generateWeeklyEFTReport(inputFilename);

    return 0;
}
