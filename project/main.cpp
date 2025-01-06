#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <sstream>

// CSVファイルを読み込む関数
std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
	std::vector<std::vector<std::string>> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			row.push_back(cell);
		}

		data.push_back(row);
	}

	file.close();
	return data;
}

// バックグラウンドスレッドでCSVを定期的に読み込む関数
void backgroundReader(const std::string& filename, std::atomic<bool>& running) {
	if (running.load()) {
		auto data = readCSV(filename);

		// 読み込んだデータを表示（デバッグ用）
		std::cout << "Read CSV:" << std::endl;
		for (const auto& row : data) {
			for (const auto& cell : row) {
				std::cout << cell << " ";
			}
			std::cout << std::endl;
		}


	}
}

int main() {
	std::atomic<bool> running(true);
	std::string filename = "data.csv";

	// バックグラウンドスレッドを開始
	std::thread readerThread(backgroundReader, filename, std::ref(running));

	// メインスレッドで他のタスクを実行
	std::cout << "Press Enter to stop..." << std::endl;
	std::cin.get(); // ユーザー入力待ち

	// スレッドを終了
	running.store(false);
	readerThread.join();

	std::cout << "Program terminated." << std::endl;
	return 0;
}