#include <iostream>
#include <vector>
#include <set>

//1
std::vector<int> union_arrays(const std::vector<int>& A, const std::vector<int>& B) {
    std::set<int> C(A.begin(), A.end());
    C.insert(B.begin(), B.end());
    return std::vector<int>(C.begin(), C.end());
}

//2
std::vector<int> intersection_arrays(const std::vector<int>& A, const std::vector<int>& B) {
    std::set<int> setA(A.begin(), A.end());
    std::set<int> C;
    for (int el : B) {
        if (setA.count(el)) {
            C.insert(el);
        }
    }
    return std::vector<int>(C.begin(), C.end());
}

//3
std::vector<int> difference_arrays(const std::vector<int>& A, const std::vector<int>& B) {
    std::set<int> setB(B.begin(), B.end());
    std::vector<int> C;
    for (int el : A) {
        if (setB.count(el) == 0) {
            C.push_back(el);
        }
    }
    return C;
}

//4
std::vector<int> symmetric_difference_arrays(const std::vector<int>& A, const std::vector<int>& B) {
    std::set<int> setA(A.begin(), A.end());
    std::set<int> setB(B.begin(), B.end());
    std::vector<int> C;

    for (int el : A) {
        if (setB.count(el) == 0) {
            C.push_back(el);
        }
    }

    for (int el : B) {
        if (setA.count(el) == 0) {
            C.push_back(el);
        }
    }

    return C;
}

int main() {
    int M, N;
    std::cout << "A: ";
    std::cin >> M;
    std::cout << "B: ";
    std::cin >> N;

    std::vector<int> A(M), B(N);
    std::cout << "A: ";
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
    }
    std::cout << "B: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int choice;
    std::cout << "\nВыберите операцию:\n";
    std::cout << "1. (A u B)\n";
    std::cout << "2. (A ∩ B)\n";
    std::cout << "3. (A \\ B)\n";
    std::cout << "4. (A △ B)\n";
    std::cout << "Введите номер операции: ";
    std::cin >> choice;

    std::vector<int> C;

    switch (choice) {
    case 1:
        C = union_arrays(A, B);
        std::cout << "Объединенный массив: ";
        break;
    case 2:
        C = intersection_arrays(A, B);
        std::cout << "Массив общих элементов: ";
        break;
    case 3:
        C = difference_arrays(A, B);
        std::cout << "Массив элементов A, которые не входят в B: ";
        break;
    default:
        std::cout << "Некорректный выбор операции." << std::endl;
        return 1;
    }

    for (int el : C) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
