#pragma once
#include <cstdint>
#include "../../helpers/bitstream.h"

namespace Megalo {
   class HUDWidgetDeclaration {
      public:
         uint8_t position;
         //
         void read(cobb::bitstream& stream) noexcept {
            this->position = stream.read_bits<uint8_t>(4);
         }
   };
}