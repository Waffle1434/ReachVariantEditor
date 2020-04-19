#pragma once
#include "base.h"

namespace Megalo {
   class OpcodeArgValueAnyVariable : public OpcodeArgValue {
      public:
         static OpcodeArgTypeinfo typeinfo;
         //
         Variable* variable = nullptr;
         //
         virtual bool read(cobb::ibitreader& stream, GameVariantDataMultiplayer& mp) noexcept override;
         virtual void write(cobb::bitwriter& stream) const noexcept override;
         virtual void to_string(std::string& out) const noexcept override;
         virtual void configure_with_base(const OpcodeArgBase&) noexcept override {}; // used for bool options so they can stringify intelligently
         virtual void decompile(Decompiler& out, Decompiler::flags_t flags = Decompiler::flags::none) noexcept override;
         //
         virtual variable_type get_variable_type() const noexcept;
         //
         OpcodeArgValueAnyVariable* create_zero_or_none() const noexcept; // See Variable::create_zero_or_none
   };
}