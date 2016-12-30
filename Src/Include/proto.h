/*
** Xtank
**
** Copyright 1993 by Pix Technologies Corp.
**
** $Id$
*/

#include "tanktypes.h"
#include "clfkr.h"
#include "bullet.h"
#include "menu.h"
#include "mdesign.h"
#include "setup.h"
#include "terminal.h"
#include "vehicle.h"
#include "graphics.h"

#if 1 || defined(__STDC__) || defined(__cplusplus)
#define P_(s) s
#else
#define P_(s) ()
#endif

/* three-d.c */
int display_anim_3d P_((int));
int init_terminal_3d P_((Terminal *));
int transform_3d P_((int *, int *));
int toggle_3d P_((int));

/* XMultiSync.c */
#ifdef Display
int XMultiSync P_((Display *dpys[], int num_dpys, int discard));
#endif

/* actions.c */
void adjust_loc P_((Loc *loc, int dx, int dy));
Bullet *make_bullet P_((Vehicle *, Loc *, WeaponType, Angle, lCoord *));
int det_tow P_((Vehicle *));
int turn_tow P_((Vehicle *, float direction));

#ifdef _XTANKLIB_H_
#ifdef FLOAT
void adjust_speed P_((FLOAT *speedx, FLOAT *speedy, double adjust));
#endif
#ifdef Loc
#endif
#ifdef Vehicle
#ifdef Bullet
Boolean get_tele P_((Vehicle *v, Bullet **b));
#endif
#ifdef Bullet
#endif
#endif
#ifdef Bullet
#endif
#ifdef Vehicle
#endif
void do_special P_((Vehicle *, SpecialType, int));
void move_view P_((int dx, int dy));
int next_live_tank P_((void));
int previous_live_tank P_((void));
int IsVehicleAlive P_((int num));
void switch_view P_((int num));
void display_pause_message P_((void));
void pause_game P_((Boolean state));
void set_game_speed P_((int spd));
void check_game_speed P_((void));
#endif
void explode P_((Bullet *b, int damage));
void expl_area P_((Bullet *b));

/* animate.c */
int animate P_((void));

/* box.c */
void box_landmark P_((Vehicle *v, Box *b));
void box_slow P_((Vehicle *v));
void box_outpost P_((Vehicle *v, Box *b, int grid_x, int grid_y));
int closest_vehicle P_((Loc *loc, Vehicle *target));
void box_type_check P_((Vehicle *v, Box *b, FLOAT *xadj, FLOAT *yadj));
int coll_outpost P_((Box *b, Loc *loc));
Coord *outpost_coordinate P_((Box *b, int fr));
void box_scroll P_((LandmarkType type, FLOAT *xadj, FLOAT *yadj));
void init_changed_boxes P_((void));
int old_box P_((Box *b, int x, int y));
void outpost_loc P_((Box *b, Loc *oloc, int grid_x, int grid_y));
int change_box P_((Box *b, int x, int y));

/* collision.c */
#ifdef Vehicle
#endif
void coll_bullets_maze P_((void));
void coll_bullets_vehicles P_((void));
void coll_vehicles_vehicles P_((void));
void coll_vehicle_walls P_((Vehicle *v));

/* cosell.c */
int comment P_((int op, int dat, Vehicle *vh1, Vehicle *vh2, Bullet *db));

#ifdef _XTANKLIB_H_
/* disc.c */
void disc_init_history P_((void));
#ifdef Bullet
#ifdef Vehicle
void disc_new_owner P_((Bullet *b, Vehicle *vh1));
#endif
Vehicle *disc_cur_owner P_((Bullet *b));
Vehicle *disc_last_owner P_((Bullet *b));
Vehicle *disc_old_owner P_((Bullet *b));
#endif
#endif
void set_disc_orbit P_((Vehicle *, Spin));
void set_disc_owner P_((Bullet *, Vehicle *));
int get_disc_team P_((Bullet *));
void release_discs P_((Vehicle *, double, Boolean));
void set_disc_team P_((Bullet *, int));

/* display.c */
void display_terminal P_((unsigned int status, int lastterm));
void display_anim P_((unsigned int status, int lastterm));
void display_vehicle P_((Vehicle *v, unsigned int status));
#ifdef Vehicle
#endif
void display_turrets P_((Vehicle *v, unsigned int status));
void display_bullets P_((unsigned int status, int lastterm));
void display_explosions P_((unsigned int status));
void display_maze P_((unsigned int status));
void display_map P_((unsigned int status));
void display_cons P_((unsigned int status));
void display_help P_((unsigned int status));
void display_pics P_((void));
void init_box_names P_((void));
#ifdef Object
#endif
void draw_objs P_((Object **, Boolean, int, int, int, int, int, int));
void draw_obj P_((Object *, int, int, int, int));
void draw_picture_string P_((Object *, int, char *, int, int, int));

/* escher.c */
void menu_frame P_((int, int, int, int, int, int, int, int));

/* explosion.c */
void make_explosion P_((Loc *, int, int));
void explode_location P_((Loc *, int, int));

/* setups.l */
int load_settings P_((char *));

/* file.c */
int save_mdesc P_((Mdesc *d));
int load_sdesc P_((Sdesc *d, char *name));
int make_sdesc P_((char *name, int *num));
void get_environment P_((void));
char *read_file P_((char *));
int save_settings P_((char *));
int ReadVehicleFormat0 P_((FILE *, Vdesc *));
int ReadVehicleFormat1 P_((FILE *, Vdesc *));
int alloc_str P_((FILE *, char **));
void convert_maze P_((Mdesc *, int));
void load_desc_lists P_((void));
int load_mdesc P_((Mdesc *, char *));
int load_vdesc P_((Vdesc *, char *));
int make_mdesc P_((char *, int *));
int make_vdesc P_((char *, int *));
int save_vdesc P_((Vdesc *));
int SaveVehicleFormat1 P_((Vdesc *));

/* game.c */
int ScreenOut P_((char *, int, int));
int ScreenOutColor P_((char *, int, int, int));
void StandardOut P_((char *, int, int));
void StandardOutColor P_((char *, int, int, int));
int capture_rules P_((Boolean));
int combat_rules P_((Boolean));
int display_game_stats P_((int));
int display_game_stats_to_current P_((int, int));
int game_rules P_((Boolean));
int race_rules P_((Boolean));
int stq_rules P_((Boolean));
int ultimate_rules P_((Boolean));
void war_init_time P_((Byte time[GRID_WIDTH][GRID_HEIGHT][MAX_TEAMS], int, int));
int war_rules P_((Boolean));

/* gr.c */
void clear_windows P_((void));
void close_terminal P_((Terminal *));
int make_terminal P_((char *));
void map_battle_windows P_((void));
void map_windows P_((void));
int open_windows P_((void));
void set_terminal P_((int));
void sync_terminals P_((Boolean));
void unmap_battle_windows P_((void));

/* highlib.c */
/* highlib.c prototypes are in lowlib.h */

/* hit.c */
void vehicle_hit_vehicle P_((Vehicle *v1, Vehicle *v2, int width, int height, int shx, int shy));
void vehicle_hit_wall P_((Vehicle *v, int grid_x, int grid_y, WallSide dir));
int bounce_damage P_((double xspeed, double yspeed, double elast));
void invalidate_maps P_((void));
void bul_hit_vehicle P_((Vehicle *v, Bullet *b, int dx, int dy));
void bul_hit_outpost P_((Bullet *b, Box *bbox, int grid_x, int grid_y));
int bul_hit_wall P_((Bullet *b, int grid_x, int grid_y, WallSide dir));
void bounce_bullet P_((Bullet *b, WallSide dir, double dx, double dy));
int damage_vehicle P_((Vehicle *v, Vehicle *damager, int damage, double angle, int height));
#if defined(Vehicle) && defined(WallSide) && defined(Box)
#endif
void assign_speed P_((Vector *vec, double xsp, double ysp));
void bounce_vehicles P_((Vehicle *v1, Vehicle *v2, int dx, int dy, double elast));
void bounce_vehicle_wall P_((Vehicle *v, int dx, int dy, double elast));
int damage_wall P_((int x, int y, WallSide dir, int damage));
Side find_affected_side P_((Vehicle *v, double angle));

/* icounter.c */
void setup_counter P_((void));
void start_counter P_((void));
void stop_counter P_((void));
void start_real_counter P_((int time));
void wait_for_real_counter P_((void));

/* init.c */
void init_settings P_((void));
void init_turrets P_((Vehicle *v));
void init_bset P_((void));
void init_eset P_((void));

/* input.c */
int get_input P_((void));
int anim_input P_((Event *));
int get_reply P_((void));
void wait_input P_((void));
int scan_input P_((void));
int input_int P_((int, char *, int, int, int, int, int, int));
void input_string P_((int, char *, char *, int, int, int, int));
int confirm P_((int, char *, int, int, int));

/* interface.c */
void reset_dynamic_entries P_((void));
void init_flags_hil P_((void));
void MakeForceString P_((char *, int));
void init_interface P_((void));
void init_comb_menus P_((void));
int sub_interface_main P_((int));
int sub_interface_force P_((int));
void sub_interface_view P_((int));
void sub_interface_load P_((int));
void sub_interface_design P_((int));
void sub_interface_help P_((int));
void sub_interface_maze P_((int, EventType));
void sub_interface_play P_((int));
void sub_interface_machine P_((int));
void sub_interface_settings P_((int));
void sub_interface_flags P_((int));
int main_interface P_((void));
void erase_other_menus P_((int mu));
static int handle_comb_button P_((Event *, int));
void do_comb P_((void));
int make_grid_combatant P_((Combatant *, int));
int combatant_to_grid P_((Combatant *, int));
void do_num P_((int, Boolean));
void display_settings P_((void));
void set_setting P_((int, int));
int setting_num P_((int));
void interface_play P_((void));
void do_view P_((int, int));
void display_mdesc P_((Mdesc *d));
void display_program P_((Prog_desc *p));
void add_players P_((void));
void add_given_player P_((int));
void remove_player P_((int));
void get_player_info P_((void));
void input_filename P_((int, char *, char *, int, int, int));
void make_prog_desc P_((void));
void load_prog_desc P_((char *, int));
void interface_load P_((int));
void interface_set_desc P_((int, char *));
void fix_desc_menu P_((int));
int ask_desc P_((int, int, int));
void ask_winning_score P_((void));
void ask_maze_density P_((void));
void display_file P_((int, char *));
void display_long_str P_((int, char *, int));
void display_title P_((Boolean));
void fix_combantants P_((int));
void comb_load_v P_((void));
void comb_load_all P_((void));

/* intersect.c */
Boolean intersect_wall P_((Loc *start, Loc *finish));
Boolean seg_intersect_obj P_((Object *obj, Segment *seg2, int xoffs, int yoffs, Coord *ipt));
Boolean obj_overlap P_((Object *obj1, Object *obj2, int xoffs, int yoffs));
Boolean seg_intersect P_((Segment *seg1, Segment *seg2, int xoffs, int yoffs, Coord *ipt));
void make_segment P_((Segment *, int, int, int, int));
int point_in_vehicle P_((Vehicle *, double, double));

/* lowlib.c */
/* lowlib.c prototypes are in lowlib.h */

/* main.c */
void debugger_break P_((void));
int main P_((int argc, char *argv[]));
int InitConfigStruct P_((CLFkr *ConfigRunning));

/* mapper.c */
SpecialStatus special_mapper P_((Vehicle *, char *, int));
static void draw_full_map P_((Box map[GRID_WIDTH][GRID_HEIGHT]));
static void draw_symbol P_((Landmark_info *s));
void full_mapper P_((int));

/* maze.c */
void setup_maze P_((void));
void make_maze P_((Mdesc *));
void build_mdesc P_((Mdesc *, Game, char *, char *, char *));
void clear_mdesc P_((Mdesc *));
void process_maze P_((void));
void make_random_maze_walls P_((void));
void remove_walls P_((int));
void make_dest_walls P_((int));
void set_box_types P_((int, FLOAT *));

/* mdesign.c */
static int handle_key P_((Event *event));
void design_maze P_((void));
static int handle_button P_((Event *event));
static void mdesign_show_anim P_((void));
void display_mdesc_maze P_((void));
void display_mdesc_info P_((Mdesc *d));
static void mdesign_show_help P_((void));
static void mdesign_clear_input P_((void));
static void change_maze P_((PixC *loc, int action));
static void unmake_maze P_((void));
static void mdesign_save P_((void));
static void mdesign_load P_((void));
static void make_landmark P_((BoxC *loc, LandmarkType type));
static void show_landmark P_((BoxC *loc));
static void set_team P_((BoxC *loc, int teamnum));
static void set_teleport_code P_((BoxC *loc));
static void show_box_fast P_((BoxC *loc));
static void show_box P_((BoxC *loc));
static void show_surrounding_walls P_((BoxC *loc));
static void move_area P_((void));
static void copy_area P_((void));
static void erase_area P_((void));
static void place_area_request P_((BoxC *loc));
static void read_area P_((BoxC vertices[2], Box temp_maze[GRID_WIDTH][GRID_HEIGHT]));
static void kill_area P_((BoxC vertices[2]));
static void put_area P_((BoxC old_vertices[2], Box temp_maze[GRID_WIDTH][GRID_HEIGHT], BoxC *new_start));
static void select_area P_((BoxC bvertices[2]));
static void xor_rectangle P_((PixC *start, PixC *end));
static int figure_insideness P_((void));
static void get_inside_spot P_((BoxC *bloc));
static void add_to_maze P_((int x, int y, BoxC *boxes, int *size));
static int check_pixel P_((PixC *loc));
static int check_pixel_extra P_((PixC *loc));
static int check_box P_((BoxC *loc));
static void box_to_pix P_((BoxC *bloc, PixC *ploc));
static void pix_to_box P_((PixC *ploc, BoxC *bloc));
static int check_wall P_((BoxC *loc, Wall wl));
static void make_wall P_((BoxC *loc, Wall wl));
static void make_destructible P_((BoxC *loc, Wall wl));
static void unmake_wall P_((BoxC *loc, Wall wl));
static void show_wall P_((BoxC *loc, Wall wl));
static void unshow_wall P_((BoxC *loc, Wall wl));
static void draw_wall P_((BoxC *loc, Wall wl, int color));
static void show_dot P_((BoxC *loc));

/* menu.c */
void menu_sys_window P_((Menu_int *menuobj, int wdw));
void menu_bare_make P_((Menu_int *menuobj, int menuid, char *title, int size, int width, int xtop, int ytop, int fntcode, int has_bar, int use_escher, int center));
void menu_set_fields P_((Menu_int *menuobj, int menuid, int val));
void menu_resize P_((Menu_int *menuobj, int menuid, int newsize));
static void menu_new_width P_((Menu_int *menuobj, int menuid, int newwid));
static void menu_display_internal P_((Menu_int *menuobj, int menuid));
static void menu_display_frame P_((Menu_int *menuobj, int menuid));
void menu_display P_((Menu_int *menuobj, int menuid));
void menu_erase P_((Menu_int *menuobj, int menuid));
static void menu_erase_internal P_((Menu_int *menuobj, int menuid));
void menu_redraw P_((Menu_int *menuobj, int menuid));
static int in_sbar P_((Menu_int *menuobj, int menuid, int x, int y));
static int menu_resolve_coord P_((Menu_int *menuobj, int menuid, int y));
static void menu_adjust P_((Menu_int *menuobj, int menuid, Event *ev));
static int menu_hit_in_border P_((Menu_int *menuobj, int menuid, int x, int y));
void menu_hit_p P_((Menu_int *menuobj, Event *ev, int *p_menuid, int *selec, int *just_scrolled));
static int menu_track_mouse P_((Menu_int *menuobj, int menuid, int y));
static void menu_highlight P_((int w, Menu *m, int item));
void menu_system_expose P_((Menu_int *menuobj));
void menu_unhighlight P_((Menu_int *menuobj, int menuid));
void menu_sys_display P_((Menu_int *menuobj));
void menu_sys_erase P_((Menu_int *menuobj));
int menu_hit P_((Menu_int *menuobj, int x, int y));

/* message.c */
void init_msg_sys P_((void));
void init_msg_terminal P_((int));
void init_msg_game P_((void));
void display_game P_((int));
void send_message P_((Vehicle *));
void set_message_data P_((Vehicle *, Event *));
int message_input P_((Event *event));
int map_input P_((Event *event));
static void display_sending P_((void));
void init_messages P_((Vehicle *));
void send_death_message P_((Vehicle *victim, Vehicle *killer));
void dispatch_message P_((Message *));
static void receive_message P_((Vehicle *v, Message *m));
static int format_message P_((Message *, char *));
void compose_message P_((Byte sender, Byte sendee, Opcode opcode, Byte * data));
void display_msg P_((int));

/* newconsole.c */
int idx2armor P_((int idx, int *sidep));
#ifdef Vehicle
int con_init P_((Vehicle *v, char *record));
int special_dummy P_((Vehicle *v, char *record, unsigned int action));
SpecialStatus special_console P_((Vehicle *v, char *record, unsigned int action));
#endif

/* newfile.c */
#ifdef Vdesc
int new_load_vdesc P_((Vdesc *d, char *name));
#endif
char *abbrev_of P_((char *str));
void init_Wnames P_((void));
#ifdef Vdesc
int SaveVehicleFormat1 P_((Vdesc *d));
#endif

/* players.c */
int init_players P_((void));

/* objects.c */
int make_objects P_((void));
Object *make_object P_((Object *obj, Bits **bitmap));
void free_objects P_((void));
void free_object P_((Object *obj));
void rotate_objects P_((void));
void rotate_object P_((Object *obj, Bits **bitmap));

/* program.c */
int set_current_vehicle P_((Vehicle *));
int init_prog_descs P_((void));
int init_specials P_((Vehicle *));
int zap_specials P_((Vehicle *));
int init_programs P_((Vehicle *));
int run_program P_((Program *));
int stop_program P_((void));
int make_programs P_((Vehicle *, int, int *));
int find_pdesc P_((char *, int *));
int check_time P_((void));
int run_all_programs P_((void));

#ifndef NO_CAMO
#ifdef Vehicle
/* camo.c */
SpecialStatus special_stealth P_((Vehicle *v, char *record, unsigned int action));
SpecialStatus special_camo P_((Vehicle *v, char *record, unsigned int action));
SpecialStatus special_rdf P_((Vehicle *v, char *record, unsigned int action));
#endif
#endif /* !NO_CAMO */

#ifndef NO_HUD
/* hud.c */
#ifdef Angle
void draw_armor P_((int armor, Angle ang));
#endif
#ifdef Vehicle
SpecialStatus special_hud P_((Vehicle *v, char *record, unsigned int action));
#endif

#endif /* !NO_HUD */

/* radar.c */
#if defined(SpecialStatus) && defined(Vehicle)
SpecialStatus special_radar P_((Vehicle *v, char *record, unsigned int action));
#endif
int full_radar P_((unsigned int status));
#ifdef Loc
int draw_char P_((Loc *loc, int c, int color));
#endif
#ifdef Vehicle
#ifdef Coord
int nr_draw_number P_((Vehicle *v, Coord *c));
#endif
SpecialStatus special_new_radar P_((Vehicle *v, char *record, unsigned int action));
int special_taclink P_((Vehicle *v, char *record, unsigned int action));
#endif
#ifdef newRadar
int nr_t_redisplay P_((newRadar *r));
#endif

/* repair.c */
#if defined(SpecialStatus) && defined(Vehicle)
SpecialStatus special_repair P_((Vehicle *v, char *record, unsigned int action));
#endif

/* scroll.c */
void draw_scrollbar P_((scrollbar *sbar));
int drag_scrollbar P_((scrollbar *sbar, int mx, int my, unsigned int button));

/* setup.c */
int standard_combatants P_((void));
int choose_program P_((void));
int robot_combatants P_((void));
int player_combatants P_((void));
int customized_combatants P_((void));
int init_terms P_((void));
int init_combatants P_((void));
int play_game P_((void));
int setup_game P_((Boolean));
#ifdef Combatant
int setup_combatant P_((Combatant *c));
#endif
#ifdef Vehicle
int setup_terminal P_((int num, Vehicle *v));
int place_vehicle P_((Vehicle *v));
int game_cleanup P_((void));
int all_terms P_((Vehicle *veh, void (*func) ()));
#endif

/* status.c */
int init_status P_((void));
#ifdef Vehicle
int init_vehicle_status P_((Vehicle *v));
#endif
int display_status P_((unsigned int disptype));
int display_status_win P_((int num, unsigned int disptype));
#ifdef Vehicle
int draw_status_from_scratch P_((Vehicle *v));
#endif
int update P_((int section, int vnum, int *old, int new, unsigned int fromscratch, int color));
int draw_dead_symbol P_((int num));
#ifdef Vehicle
int compute_minarmor P_((Vehicle *v));
int compute_totammo P_((Vehicle *v));
#endif

/* thread.c */
#ifdef Thread
Thread *thread_setup P_((void));
Thread *thread_init P_((char *buf, unsigned int bufsize, Thread *(*func) ()));
#endif

/* threadglue.c */
int init_threader P_((void));

/* unix.c */
int check_internet P_((int num_clients, char **client));
#ifndef hp9000s800
int compile_module P_((char *module_name, char **symbol, char **code, char *error_name, char *output_name));
#ifndef mips
/*struct nlist *namelist P_((int fd, struct exec * hdr)); */
#endif
#else /* hp9000s800 */
int compile_module P_((char *module_name, Prog_desc **symbol, char **code, char *error_name, char *output_name));
#endif /* hp9000s800 */

/* update.c */
#ifdef Vehicle
int update_vector P_((Vehicle *v));
#endif
#ifdef Turret
int update_turret P_((Turret *t));
#endif
int update_bullets P_((void));
#ifdef Bullet
#endif
int update_disc P_((Bullet *b));
int update_vehicle P_((Vehicle *v));
int update_explosions P_((void));
int update_maze_flags P_((void));
int update_rotation P_((Vehicle *v));
int update_specials P_((void));
int update_screen_locs P_((void));

/* util.c */
int init_random P_((void));
int rnd P_((int mx));
#ifdef FLOAT
FLOAT rnd_interval P_((double mn, double mx));
#endif
int display_mesg P_((int w, char *string, int row, int font));
int display_mesg2 P_((int w, char *string, int column, int row, int font));
int display_mesg1 P_((int w, char *string, int column, int row, int font, int color));
int free_everything P_((void));
long idist P_((long x1, long y1, long x2, long y2));

/* vdesign.c */
int design_vehicle P_((void));
int init_vdesign_interface P_((void));
#ifdef Vdesc
int vdesign_specials_hil P_((Vdesc *d));
void vdesign_load P_((Vdesc *d));
void vdesign_save P_((Vdesc *d));
int vdesign_interface P_((Vdesc *d));
int erase_vdesign_menus P_((int mu));
int init_vdesc P_((Vdesc *d));
#endif
void display_vdesc P_((Vdesc *d, int status));
int compute_vdesc P_((Vdesc *));
int init_vdesign P_((void));

/* vehicle.c */
#ifdef Vehicle
void make_turrets P_((Vehicle *v));
void make_specials P_((Vehicle *v, Flag which));
void unmake_specials P_((Vehicle *v));
Vehicle *make_vehicle P_((Vdesc *d, Combatant *c));
void inactivate_vehicle P_((Vehicle *victim));
void explode_vehicle P_((Vehicle *victim));
#endif
#ifdef Terminal
void make_observer P_((Terminal *trm));
#endif
int kill_vehicle P_((Vehicle *victim, Vehicle *killer));
int unmake_vehicle P_((Vehicle *v));
int activate_vehicle P_((Vehicle *v));

/* x11.c */
int open_graphics P_((void));
int close_graphics P_((void));
int reset_video P_((void));
int set_video P_((Video *video));
#ifdef Video
Video *make_video P_((char *name));
#endif
void close_video P_((Video *));
int make_parent P_((void));
int make_window P_((int w, int x, int y, int width, int height, int border));
int beep_window P_((void));
int map_window P_((int w));
int unmap_window P_((int w));
int clear_window P_((int w));
int draw_text_left P_((int window, int x, int y, char *str, int font, int func, int color));
int draw_text P_((int w, int x, int y, char *str, int font, int func, int color));
int should_disp_name P_((void));
int draw_text_rc P_((int w, int x, int y, char *str, int font, int color));
int clear_text_rc P_((int w, int x, int y, int width, int height, int font));
int flush_output P_((void));
#ifdef Boolean
#endif
int sync_output P_((Boolean discard));
#if defined(Video) && defined(Boolean)
int multi_sync P_((Video *video[], int num_videos, Boolean discard));
#endif
#ifdef Event
#endif
int get_events P_((int *, Event *));
int follow_mouse P_((int w, Boolean status));
void button_up P_((int w, Boolean status));
int make_gcs P_((void));
int set_font_path P_((char *fontdir));
int make_cursors P_((void));
int make_cursor P_((int c, int width, int height, int xhot, int yhot, char bits[], char mask[]));
int set_cursor P_((int c));
int font_height P_((int font));
int font_string_width P_((char *str, int font));
#ifdef Picture
int make_picture P_((Picture *pic, char *bitmap));
int free_picture P_((Picture *pic));
#ifdef Byte
Byte *rotate_pic_90 P_((Picture *pic, Picture *rot_pic, Byte * bitmap));
Byte *rotate_pic_180 P_((Picture *pic, Picture *rot_pic, Byte * bitmap));
#endif
#endif
#if defined(Display) && defined(XErrorEvent)
int liteXerror P_((Display *dpy, XErrorEvent *err));
#endif
char *get_default P_((char *itemname, char *itemclass, char *defaultstr));
int get_num_default P_((char *itemname, char *itemclass, int defaultnum));

#undef P_
