
/*
** Xtank
**
** Copyright 1993 by Pix Technologies Corp.
**
** settings.h
*/

/*
$Author: lidl $
$Id: settings.h,v 1.1.1.1 1995/02/01 00:25:43 lidl Exp $
*/

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include "maze.h"

/* game settings that are available to robot players */
  typedef struct {
	  Game game;				/* combat, war, ultimate, capture, race */
	  Boolean ricochet;			/* whether bullets bounce off walls */
	  Boolean rel_shoot;		/* whether shooter's speed added to bullet's */
	  Boolean no_wear;			/* whether vehicles take damage & lose fuel */
	  Boolean restart;			/* whether vehicles restart after death */
	  Boolean full_map;			/* whether vehicles start out with full map */
	  Boolean pay_to_play;		/* whether vehicles have to "pay to play" */
	  Boolean no_nametags;		/* whether vehicles are anonymous */
	  Boolean team_score;		/* whether to use team scoring */
	  Boolean player_teleport;	/* whether players can teleport */
	  Boolean disc_teleport;	/* whether discs can teleport */
	  Boolean teleport_from_team;	/* whether we can teleport from */
	  /* team teleports */
	  Boolean teleport_from_neutral;	/* whether we can teleport from  */
	  /* neutral teleports */
	  Boolean teleport_to_team;	/* whether we can teleport to  */
	  /* team teleports */
	  Boolean teleport_to_neutral;	/* whether we can teleport to  */
	  /* neutral teleports */
	  Boolean teleport_any_to_any;	/* if set, every player can use */
	  /* every team's teleports, but */
	  /* pairs of equal coloured */
	  /* teleports must still be used - */
	  /* for example, a green teleport */
	  /* will never teleport to a blue */
	  /* one, only to either a neutral */
	  /* one or another green one. */
	  Boolean war_goals_only;	/* in Warfare, only goals are counted */
	  Boolean relative_disc;	/* relative speeds are used for disc damage */
	  Boolean ultimate_own_goal;/* in Ultimate, must score in own goal */
	  int winning_score;		/* score needed to win the game */
	  int takeover_time;		/* how long you have to be in a square in order
				   to capture it (in War game) */
	  int outpost_strength;		/* firepower of outposts (0-10) */
	  int shocker_walls;		/* how much extra damage walls do (0-10) */
	  FLOAT scroll_speed;		/* speed of scroll boxes (0-10) */
	  FLOAT slip_friction;		/* friction in slip boxes (0-1) */
	  FLOAT normal_friction;	/* friction in all other boxes (0-1) */
	  FLOAT disc_friction;		/* friction factor applied to disc (0-1) */
	  FLOAT disc_speed;			/* throwing speed of the disc (0-1) */
	  FLOAT disc_damage;		/* damage done by disc when caught (0-1) */
	  FLOAT disc_heat;			/* amount of heat generated by disc (0-1) */
	  FLOAT box_slowdown;		/* slowdown caused by slow boxes (0-1) */
	  FLOAT owner_slowdown;		/* how much to slow down disc owner (0-1) */
	  int num_discs;		/* How many discs in the madman game (1-10) */
  }
Settings_info;

  typedef struct {
	  int game_speed;			/* max. number of frames per second */
	  Mdesc *mdesc;				/* pointer to maze description */
	  int maze_density;			/* % of walls kept in random maze (0 - 100) */
	  Boolean point_bullets;	/* whether bullets are points or pictures */
	  Boolean commentator;		/* whether commentator will comment on game */
	  Boolean robots_dont_win;	/* whether robots can win a game */
	  Boolean max_armor_scale;	/* scales armor to max instead of per side */
	  int difficulty;			/* difficulty of enemy robots (0 - 10) */
	  Settings_info si;			/* lots of other info that is made available to
				   robot players */
  }
Settings;


#endif /* ndef _SETTINGS_H_ */
