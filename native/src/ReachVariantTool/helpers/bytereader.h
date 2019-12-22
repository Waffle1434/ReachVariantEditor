#pragma once
#include <cstdint>
#include <type_traits>
#include "endianness.h"

namespace cobb {
   class bytereader {
      protected:
         const uint8_t* buffer = nullptr;
         uint32_t length = 0;
         uint32_t offset = 0;
      public:
         bytereader(const uint8_t* b, uint32_t l) : buffer(b), length(l) {};
         bytereader(const void* b, uint32_t l) : buffer((const uint8_t*)b), length(l) {};
         //
         inline const uint8_t* data() const noexcept  { return this->buffer; }
         inline uint32_t get_bitpos()  const noexcept { return this->offset * 8; };
         inline uint32_t get_bytepos() const noexcept { return this->offset; }
         inline void set_bytepos(uint32_t bytepos) noexcept { this->offset = bytepos; }
         //
         void read(void* out, uint32_t length) noexcept;
         void read(uint8_t* out, uint32_t length) noexcept;
         template<typename T> void read(T out[], cobb::endian_t endianness = cobb::endian::little) noexcept {
            uint32_t count = std::extent<decltype(out)>::value;
            if (sizeof(T) == 1) {
               this->read(out, std::extent<decltype(out)>::value);
            } else {
               for (uint32_t i = 0; i < count; i++)
                  this->read(out[i], endianness);
            }
         };
         template<typename T> void read(T& out, cobb::endian_t endianness = cobb::endian::little) noexcept {
            out = *(T*)(this->buffer + this->offset);
            this->offset += sizeof(out);
            //
            if (std::is_integral_v<T> && sizeof(T) > 1)
               if (endianness != cobb::endian::native)
                  out = cobb::byteswap(out);
         };
         inline void pad(uint32_t bytes) {
            this->offset += bytes;
         }
         inline void skip(uint32_t bytes) {
            this->offset += bytes;
         }
         //
         void read_string(char* out, uint32_t length, cobb::endian_t endianness = cobb::endian::little) noexcept;
         void read_wstring(wchar_t* out, uint32_t length, cobb::endian_t endianness = cobb::endian::little) noexcept;
   };
}