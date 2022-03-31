// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
  // UNUSED(attacker_position);
  // UNUSED(defender_spy);

  // TODO: Implement Attacker logic here

  // A partir de um número aleatório entre 1 e 9 o meu atacante executa algum movimento
  // Se o numero aleatorio for 9, ele checa o spy e caso o 
  int random = rand() % 9;

  position_t current_defender_position;

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
    new_direction = (direction_t) DIR_RIGHT;
  }  
  else if(random == 9){
    // Se o numero aleatorio for 9, ele checa o spy    
    current_defender_position= get_spy_position(defender_spy); 

    // Se o defensor estiver em uma linha abaixo a do atacante, move para a diagonal superior direita em direção ao lado oposto
    if(current_defender_position.i < attacker_position.i){
      new_direction = (direction_t) DIR_UP_RIGHT;
    }

    // Se o defensor estiver na linha igual a do atacante, ele move o atacante para cima ou para baixo de forma pseudoaleatória
    else  if(current_defender_position.i == attacker_position.i){
      int another_random = rand() % 2;
      if(another_random == 1){
        new_direction = (direction_t) DIR_UP;
      }
      else{
        new_direction = (direction_t) DIR_DOWN;
      }
    }

    // Senão o atacante move para a diagonal inferior direita, sempre em direção ao lado oposto
    else{
      new_direction = (direction_t) DIR_DOWN_RIGHT;
    }
  }
  return  new_direction;

}

/*----------------------------------------------------------------------------*/
