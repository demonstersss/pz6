#include <iostream>
#define LENGTH 10


void initialize(unsigned int(&arr)[]) {
	for (char i = 0; i < LENGTH; i++)
	{
		arr[i] = rand() % 52;
	}
}
void sort(unsigned int(&arr)[]) {
	for (char i = 0; i < LENGTH; i++)
	{
		for (char j = 0; j < LENGTH - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				char temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void print(unsigned int(&arr)[]) {
	for (char i = 0; i < LENGTH; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void print(int element) {
	std::cout << element << std::endl;
}
int find(unsigned int(&arr)[], int element) {
	int left = 0;
    int right = LENGTH - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Защита от переполнения

        if (arr[mid] == (unsigned int)element) {
            return mid;
        }
        
        if (arr[mid] < (unsigned int)element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}



bool isHex(char c) {
	return (c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F');
}
void task2(std::string& text) {
	for (short i = 0; i < text.length(); ++i) {
		if (text[i] == '#') {
			short start = i;
			short count = 0;

			while (i + 1 < text.length() && isHex(text[i + 1])) {
				i++;
				count++;
			}

			if (count == 3 || count == 6) {
				std::cout << text.substr(start, count + 1) << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	unsigned int arr[LENGTH];
	initialize(arr);
	print(arr);
	sort(arr);
	print(arr);
	print(find(arr, 44));

	std::string text = "Цвета: #f6F601, #000000, #fff, #A8A8A8, а также #1234.";
	task2(text);


}
