#include "mission.h"
#include "game.h"
#include "overmapbuffer.h"
#include "npc.h"

void mission_fail::kill_npc( mission *miss )
{
    if( npc *const elem = g->npc_by_id( miss->get_npc_id() ) ) {
        elem->die( nullptr );
        // Actuall removoal of the npc is done in game::cleanup_dead
    }
    npc *n = overmap_buffer.find_npc( miss->get_npc_id() );
    if( n != nullptr && !n->is_dead() ) {
        // in case the npc was not inside the reality bubble, mark it as dead anyway.
        n->marked_for_death = true;
    }
}
