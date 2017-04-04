#include "vector.hpp"

vector_t::vector_t() noexcept
{
  size_ = capacity_ = 0;
  this->ptr_ = nullptr;
}

vector_t::vector_t(unsigned int size)
{
  size_ = size;
	capacity_ = size;
	ptr_ = new int[capacity_]();
}

vector_t::vector_t(const vector_t& other)
{
  size_ = other.size_;
	capacity_ = other.capacity_;
	ptr_ = new int[capacity_];
	for (int i = 0; i < size_; ++i)
		ptr_[i] = other.ptr_[i];
}

auto vector_t::operator=(const vector_t& other) -> vector_t&
{
  if (&other != this)
  {
    delete[] ptr_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    ptr_ = new int[capacity_];
    for (int i = 0; i < size_; ++i)
      ptr_[i] = other.ptr_[i];
  }
	return *this;
}

vector_t::~vector_t() noexcept
{
  delete[]ptr_;
}

auto vector_t::size() const noexcept -> unsigned int
{
  return size_;
}

auto vector_t::capacity() const noexcept -> unsigned int
{
  return capacity_;
}

auto vector_t::push_back(int value) -> void
{
  if (capacity_ == 0)
		capacity_ = 1;
	if (size_ == capacity_)
		capacity_ *= 2;
	int* ptr = new int[capacity_];
	for (int i = 0; i < (size_ + 1); ++i)
		ptr[i] = ptr_[i];
	delete[] ptr_;
	ptr_ = ptr;
	ptr_[size_] = value;
	size_++;
}

auto vector_t::operator[](unsigned int index) const noexcept -> int
{
  return ptr_[index];
}
