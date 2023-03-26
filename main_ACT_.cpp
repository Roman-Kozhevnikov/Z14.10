#include "AutoComplText.h"


int main()
{
	std::string wordbook[] = { "duck", "durk", "dove", "dog", "do", "doganes", "zebra", "zubr", "ze", "zea", "wordme", "wordus" };
	int n = sizeof(wordbook) / sizeof(wordbook[0]);

	
	bool _true = true;	
	std::string str;
	while (_true)
	{
		Trie wb;
		wb.complitWordBook(wordbook, n);
		std::cout << "Chose the mode: 1 - to get autocomplite, 2 - to quet \n";
		
		char choose;
		std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
		switch (choose)
		{
			
		case '1' : 			       
			       std::cout << "complit the word :  ";
			       getline(std::cin, str);			      
				   wb.findAllWordsByPrefix(str);				  
				   
				   std::cout << std::endl;
				   break;
		case '2':  
			       _true = false;
				   break;
		default:
			break;
		}

	}
	
	//Trie wb;
	//wb.complitWordBook(wordbook, n);
	//string str1 = "doga"; // -- распечатает "nes"
	//string str2 = "w";  // -- распечатает "ord"
	//wb.showUnicPostPrefix(str1);
	//wb.showUnicPREprefix(str2);


	std::cout << std::endl;
	std::cout << "Done!";

	return 0;
		
}
