#include <iostream>
#include <string>
#include <chrono>

// 時間をマイクロ秒で計測する関数
template <typename Func>
uint64_t measureTimeMicroseconds(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {
    // 100000文字の'a'で初期化されたstd::string
    std::string a(100000, 'a');

    // コピー処理の時間を計測
    uint64_t copyTime = measureTimeMicroseconds([&]() {
        std::string b = a; // コピー
        });

    // 移動処理の時間を計測
    uint64_t moveTime = measureTimeMicroseconds([&]() {
        std::string c = std::move(a); // 移動
        });

    // 結果を表示
    std::cout << "コピーにかかった時間: " << copyTime << " us" << std::endl;
    std::cout << "移動にかかった時間: " << moveTime << " us" << std::endl;

    return 0;
}