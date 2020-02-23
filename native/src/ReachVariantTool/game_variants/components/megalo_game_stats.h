#pragma once
#include "../../helpers/bitnumber.h"
#include "../../helpers/bitwriter.h"
#include "../../formats/localized_string_table.h"
#include "../../helpers/refcounting.h"
#include "../../helpers/stream.h"

class ReachMegaloGameStat : public cobb::indexed_refcountable {
   public:
      enum class Format : uint8_t {
         number,
         number_with_sign,
         percentage,
         time,
      };
      enum class Sort : int8_t {
         ascending = -1,
         ignored,
         descending,
         obsolete_2,
      };
      int8_t index = -1;
      MegaloStringRef   name;
      MegaloStringIndex nameIndex;
      Format format      = Format::number;
      Sort   sortOrder   = Sort::ascending;
      bool   groupByTeam = false;
      //
      void read(cobb::ibitreader&) noexcept;
      void postprocess_string_indices(ReachStringTable& table) noexcept;
      void write(cobb::bitwriter& stream) noexcept;
};