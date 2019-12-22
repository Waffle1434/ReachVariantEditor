#include "opcode_arg.h"
#include "variables_and_scopes.h"

#include "opcode_arg_types/scalar.h"
#include "opcode_arg_types/player.h"
#include "opcode_arg_types/object.h"
#include "opcode_arg_types/team.h"
#include "opcode_arg_types/timer.h"

#include "parse_error_reporting.h"

namespace Megalo {
   extern OpcodeArgValue* OpcodeArgAnyVariableFactory(cobb::bitreader& stream) {
      uint8_t type = stream.read_bits<uint8_t>(3);
      switch ((variable_type)type) {
         case variable_type::scalar:
            return OpcodeArgValueScalar::factory(stream);
         case variable_type::timer:
            return OpcodeArgValueTimer::factory(stream);
         case variable_type::team:
            return OpcodeArgValueTeam::factory(stream);
         case variable_type::player:
            return OpcodeArgValuePlayer::factory(stream);
         case variable_type::object:
            return OpcodeArgValueObject::factory(stream);
      }
      auto& error = ParseState::get();
      error.signalled = true;
      error.cause     = ParseState::what::bad_variable_type;
      error.extra[0]  = type;
      return false;
   }
   extern OpcodeArgValue* OpcodeArgTeamOrPlayerVariableFactory(cobb::bitreader& stream) {
      uint8_t type = stream.read_bits<uint8_t>(2);
      switch (type) {
         case 0: // Team
            return OpcodeArgValueTeam::factory(stream);
         case 1: // Player
            return OpcodeArgValuePlayer::factory(stream);
         case 2: // All Players
            return OpcodeArgValueAllPlayers::factory(stream);
      }
      auto& error = ParseState::get();
      error.signalled = true;
      error.cause     = ParseState::what::bad_player_or_team_var_type;
      error.extra[0]  = type;
      return false;
   }
}