/*
** Xtank
**
** Copyright 1988 by Terry Donahue
**
** vstructs.h
*/

/*
$Author: lidl $
$Id: vstructs.h,v 2.7 1992/03/31 21:49:23 lidl Exp $

$Log: vstructs.h,v $
 * Revision 2.7  1992/03/31  21:49:23  lidl
 * Post Aaron-3d patches, camo patches, march patches & misc PIX stuff
 *
 * Revision 2.6  1992/02/04  07:27:25  aahz
 * added the size of arrays to the extern statements so sizeof()
 * doesn't get a zero.
 *
 * Revision 2.5  1992/01/29  08:39:11  lidl
 * post aaron patches, seems to mostly work now
 *
 * Revision 2.4  1991/12/10  01:21:04  lidl
 * change all occurances of "float" to "FLOAT"
 *
 * Revision 2.3  1991/02/10  13:52:07  rpotter
 * bug fixes, display tweaks, non-restart fixes, header reorg.
 *
 * Revision 2.2  91/01/20  09:59:26  rpotter
 * complete rewrite of vehicle death, other tweaks
 * 
 * Revision 2.1  91/01/17  07:13:34  rpotter
 * lint warnings and a fix to update_vector()
 * 
 * Revision 2.0  91/01/17  02:10:52  rpotter
 * small changes
 * 
 * Revision 1.1  90/12/29  21:03:20  aahz
 * Initial revision
 * 
*/

#define MIN_ARMOR        0
#define MAX_ARMOR      999

#define OVER_WEIGHT      (1<<0)
#define OVER_SPACE       (1<<1)
#define BAD_MOUNT        (1<<2)
#define MIS_MOUNT        (1<<3)

typedef struct
{
    char *type;
    int   defense;
    int   weight;
    int   space;
    int   cost;
} Armor_stat;

typedef struct
{
    char *type;
    int   damage;
    int   range;
    int   max_ammo;
    int   reload_time;
    int   ammo_speed;
    int   weight;
    int   space;
    int   frames;
    int   heat;
    int   ammo_cost;
    int   cost;
#ifndef NO_TIMED_REFILL
    int   refill_time;
#endif /* !NO_TIMED_REFILL */
} Weapon_stat;

typedef struct
{
    char *type;
    int   power;
    int   weight;
    int   space;
    int   fuel_cost;
    int   fuel_limit;
    int   cost;
} Engine_stat;

typedef struct
{
    char *type;
    int   size;
    int   weight;
    int   weight_limit;
    int   space;
    FLOAT drag;
    int   handling_base;
    int   turrets;
    int   cost;
} Body_stat;

typedef struct
{
    char *type;
    int   handling_adj;
    int   cost;
} Suspension_stat;

typedef struct
{
    char *type;
    FLOAT friction;
    int   cost;
} Tread_stat;

typedef struct
{
    char *type;
    FLOAT elasticity;
    int   cost;
} Bumper_stat;

typedef struct
{
    char *type;
    int   cost;
} Special_stat;

typedef struct
{
    int   weight;
    int   space;
    int   cost;
} Heat_sink_stat;



extern Heat_sink_stat heat_sink_stat;
extern Weapon_stat weapon_stat[VMAX_WEAPONS];
extern Armor_stat armor_stat[MAX_ARMORS];
extern Engine_stat engine_stat[MAX_ENGINES];
extern Body_stat body_stat[MAX_BODIES];
extern Suspension_stat suspension_stat[MAX_SUSPENSIONS];
extern Tread_stat tread_stat[MAX_TREADS];
extern Bumper_stat bumper_stat[MAX_BUMPERS];
extern Special_stat special_stat[MAX_SPECIALS];
