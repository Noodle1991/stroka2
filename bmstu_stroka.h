#pragma once

#include <iostream>
/*переименовать stroka -> string
 * очевидно, что мы не используем
 * транслитицизмы
 * */
namespace bmstu {
    template<typename T>
    class basic_string;

    using string = basic_string<char>;
    using wstring = basic_string<wchar_t>;

    template<typename T>
    class basic_string {
    public:

///конструктор по умолчанию
        basic_string() {
            ptr_ = new T[1];
            *ptr_ = '\0';
            size_ = 0;
        }

/// Конструктор с параметром "cи строкой"
        basic_string(const T *c_str) {
            clean_();
            size_ = strlen_(c_str);
            ptr_ = static_cast<T *>(new T[size_ + 1]);
            ptr_[size_] = 0;
            for (int c = 0; c < size_; ++c) {
                ptr_[c] = c_str[c];
            }
        }

/// Копирующий конструктор
        basic_string(const basic_string<T> &other) {
            clean_();
            size_ = other.size_;
            ptr_ = new T[size_ + 1];
            ptr_[size_] = 0;
            for (int i = 0; i < size_; i++) {
                *(ptr_ + i) = other.c_str()[i];
            }
        }

/// Конструктор перемещения
        basic_string(basic_string<T> &&dying) noexcept {
            if (this != &dying) {
                clean_();
                ptr_ = dying.ptr_;
                size_ = dying.size_;
                dying.ptr_ = new T[1];
                dying.size_ = 0;
            }
        }

/// Деструктор
        ~basic_string() {
            delete[] ptr_;
        }

/// Геттер на си-строку
        const T *c_str() const {
            return static_cast<const T * >(ptr_);
        }

/// Геттер на размер
        size_t size() const {
            return size_;
        }

/// Оператор копирующего присваивания
        basic_string &operator=(const basic_string<T> &other) {
            if (this != &other) {
                clean_();
                size_ = other.size_;
                ptr_ = new T[size_ + 1];
                ptr_[size_] = 0;
                for (int i = 0; i < size_; i++) {
                    *(ptr_ + i) = other.c_str()[i];
                }
            }
            return *this;
        }

/// Оператор перемещающего присваивания
        basic_string &operator=(basic_string<T> &&other) noexcept {
            if (this != &other) {
                clean_();
                ptr_ = other.ptr_;
                size_ = other.size_;
                other.ptr_ = new T[1];
                other.size_ = 0;
            }
            return *this;
        }

/// Оператор присваивания си строки
        basic_string &operator=(const T *c_str) {
            clean_();
            size_ = strlen_(c_str);
            ptr_ = new T[size_ + 1];
            ptr_[size_] = 0;
            for (int i = 0; i < size_; i++) {
                ptr_[i] = c_str[i];
            }
            return *this;
        }

/*Все все понимают*/

        friend bmstu::basic_string<T> operator+(const basic_string<T> &left, const basic_string<T> &right) {
            bmstu::basic_string<T> result(left);
            result += right;
            return result;
        }

        template<class OS>
        ///типа std::ostream
        /* скорее так правильно что делать для других потоков*/
        friend OS &operator<<(OS &os, const basic_string<T> &obj) {
            os << obj.c_str();
            return os;
        }

        template<class IS>
        ///типа std::istream
        friend IS &operator>>(IS &is, basic_string<T> &obj) {
            basic_string result;
            T buf = ' ';
            while (is.good()) {
                buf = is.get();
                if (buf == -1) {
                    break;
                }
                result += buf;
            }
            obj = std::move(result);
            return is;
        }

        basic_string &operator+=(const basic_string<T> &other) {
            size_t new_size = size_ + other.size_;
            auto new_ptr = new T[new_size + 1];
            for (int i = 0; i < size_; i++) {
                new_ptr[i] = ptr_[i];
            }

            for (int i = 0; i < other.size_; i++) {
                new_ptr[i + size_] = other.ptr_[i];
            }

            new_ptr[new_size] = 0;
            clean_();
            ptr_ = new_ptr;
            size_ = new_size;
            return *this;
        }

        basic_string &operator+=(T symbol) {
            auto new_size = size_ + 1;
            auto new_ptr = new T[new_size + 1];
            for (auto i = 0; i < size_; ++i) {
                new_ptr[i] = ptr_[i];
            }
            new_ptr[new_size - 1] = symbol;
            new_ptr[new_size] = 0;
            clean_();
            ptr_ = new_ptr;
            size_ = new_size;
            return *this;
        }

        T &operator[](size_t index) {
            if (index < size_) {
                return *(ptr_ + index);
            }
            throw std::runtime_error("No index" + std::to_string(index));
        }

    private:
/// приватные хелперы
        static size_t strlen_(const T *str) {
            size_t result = 0;
            while (*str) {
                result = result + 1;
                str = str + 1;
            }
            return result;
        }

        void clean_() {
            if (ptr_ != nullptr) {
                delete[] ptr_;
                ptr_ = nullptr;
            }
            size_ = 0;
        }

/// Поля класса
        T *ptr_ = nullptr;
        int size_;
    };
}