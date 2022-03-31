// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  // UNUSED(defender_position);
  // UNUSED(attacker_spy);
  
    
  // TODO: Implement Defender logic here

  int random = rand() % 9;

  position_t current_attacker_position;

  direction_t new_direction = DIR_STAY;

  if(random == 1){
    new_direction = (direction_t) DIR_RIGHT;
  }
  else if(random == 2){
    new_direction = (direction_t)  DIR_DOWN_RIGHT;
  }
  else if(random == 3){
    new_direction = (direction_t) DIR_UP_RIGHT;
  }
  else if(random == 4){
    new_direction = (direction_t) DIR_UP;
  }
  else if(random == 5){
    new_direction = (direction_t) DIR_DOWN;
  }
  else if(random == 6){
    new_direction = (direction_t) DIR_DOWN_LEFT;
  }
  else if(random == 7){
    new_direction = (direction_t) DIR_UP_LEFT;
  }
  else if(random == 8){
    new_direction = (direction_t) DIR_LEFT;
  }  
  else if(random == 9){
    // Se o numero aleatorio for 9, ele checa o spy    
    current_attacker_position = get_spy_position(attacker_spy); 

    // Se o defensor estiver na linha igual a do atacante, move para a esquerda em direção direta ao atacante
    if(current_attacker_position.i == defender_position.i){
      new_direction = (direction_t) DIR_LEFT;
    }

    // Se o defensor estiver em uma linha acima a do atacante, aproxima na direção dele na diagonal
    else if(current_attacker_position.i < defender_position.i){
      new_direction = (direction_t) DIR_DOWN_LEFT;
    }

    // Senão o atacante move para a outra diagonal, também em direção ao atancante que agora está em uma linha acima
    else{
      new_direction = (direction_t) DIR_UP_LEFT;
    }
  }
  return new_direction;
}

/*----------------------------------------------------------------------------*/
