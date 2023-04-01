//
//  Copyright (C) 1999 by
//  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
// DESCRIPTION:
//      Created by a sound utility.
//      Kept as a sample, DOOM2 sounds.
//
//-----------------------------------------------------------------------------

// killough 5/3/98: reformatted

#include "doomtype.h"
#include "sounds.h"

//
// Information about all the music
//

musicinfo_t S_music[] = {
  { 0 },
  { "e1m1", 0 },
  { "e1m2", 0 },
  { "e1m3", 0 },
  { "e1m4", 0 },
  { "e1m5", 0 },
  { "e1m6", 0 },
  { "e1m7", 0 },
  { "e1m8", 0 },
  { "e1m9", 0 },
  { "e2m1", 0 },
  { "e2m2", 0 },
  { "e2m3", 0 },
  { "e2m4", 0 },
  { "e2m5", 0 },
  { "e2m6", 0 },
  { "e2m7", 0 },
  { "e2m8", 0 },
  { "e2m9", 0 },
  { "e3m1", 0 },
  { "e3m2", 0 },
  { "e3m3", 0 },
  { "e3m4", 0 },
  { "e3m5", 0 },
  { "e3m6", 0 },
  { "e3m7", 0 },
  { "e3m8", 0 },
  { "e3m9", 0 },
  { "e4m1", 0 },
  { "e4m2", 0 },
  { "e4m3", 0 },
  { "e4m4", 0 },
  { "e4m5", 0 },
  { "e4m6", 0 },
  { "e4m7", 0 },
  { "e4m8", 0 },
  { "e4m9", 0 },
  { "inter", 0 },
  { "intro", 0 },
  { "bunny", 0 },
  { "victor", 0 },
  { "introa", 0 },
  { "runnin", 0 },
  { "stalks", 0 },
  { "countd", 0 },
  { "betwee", 0 },
  { "doom", 0 },
  { "the_da", 0 },
  { "shawn", 0 },
  { "ddtblu", 0 },
  { "in_cit", 0 },
  { "dead", 0 },
  { "stlks2", 0 },
  { "theda2", 0 },
  { "doom2", 0 },
  { "ddtbl2", 0 },
  { "runni2", 0 },
  { "dead2", 0 },
  { "stlks3", 0 },
  { "romero", 0 },
  { "shawn2", 0 },
  { "messag", 0 },
  { "count2", 0 },
  { "ddtbl3", 0 },
  { "ampie", 0 },
  { "theda3", 0 },
  { "adrian", 0 },
  { "messg2", 0 },
  { "romer2", 0 },
  { "tense", 0 },
  { "shawn3", 0 },
  { "openin", 0 },
  { "evil", 0 },
  { "ultima", 0 },
  { "read_m", 0 },
  { "dm2ttl", 0 },
  { "dm2int", 0 },
  { NULL, 0 }, // NUMMUSIC
  { "musinfo", 0 }
};

//
// Information about all the sfx
//
// killough 12/98: 
// Reimplemented 'singularity' flag, adjusting many sounds below

#define SOUND_LINK(n, s, p, l, i) \
  {.name = n, \
   .singularity = s, \
   .priority = p, \
   .link = l ? &original_S_sfx[l] : NULL, \
   .pitch = i, \
   .volume = -1, \
   .data = NULL, \
   .usefulness = -1, \
   .lumpnum = -1, \
   .alen = 0}

#define SOUND(n, s, p) \
  SOUND_LINK(n, s, p, 0, -1)

sfxinfo_t original_S_sfx[NUMSFX] = {
  SOUND("none",   sg_none,    0), // S_sfx[0] needs to be a dummy for odd reasons.

  SOUND("pistol", sg_none,   64),
  SOUND("shotgn", sg_none,   64),
  SOUND("sgcock", sg_none,   64),
  SOUND("dshtgn", sg_none,   64),
  SOUND("dbopn",  sg_none,   64),
  SOUND("dbcls",  sg_none,   64),
  SOUND("dbload", sg_none,   64),
  SOUND("plasma", sg_none,   64),
  SOUND("bfg",    sg_none,   64),
  SOUND("sawup",  sg_none,   64),
  SOUND("sawidl", sg_none,  118),
  SOUND("sawful", sg_none,   64),
  SOUND("sawhit", sg_none,   64),
  SOUND("rlaunc", sg_none,   64),
  SOUND("rxplod", sg_none,   70),
  SOUND("firsht", sg_none,   70),
  SOUND("firxpl", sg_none,   70),
  SOUND("pstart", sg_none,  100),
  SOUND("pstop",  sg_none,  100),
  SOUND("doropn", sg_none,  100),
  SOUND("dorcls", sg_none,  100),
  SOUND("stnmov", sg_none,  119),
  SOUND("swtchn", sg_none,   78),
  SOUND("swtchx", sg_none,   78),
  SOUND("plpain", sg_none,   96),
  SOUND("dmpain", sg_none,   96),
  SOUND("popain", sg_none,   96),
  SOUND("vipain", sg_none,   96),
  SOUND("mnpain", sg_none,   96),
  SOUND("pepain", sg_none,   96),
  SOUND("slop",   sg_none,   78),
  SOUND("itemup", sg_itemup, 78),
  SOUND("wpnup",  sg_wpnup,  78),
  SOUND("oof",    sg_oof,    96),
  SOUND("telept", sg_none,   32),
  SOUND("posit1", sg_none,   98),
  SOUND("posit2", sg_none,   98),
  SOUND("posit3", sg_none,   98),
  SOUND("bgsit1", sg_none,   98),
  SOUND("bgsit2", sg_none,   98),
  SOUND("sgtsit", sg_none,   98),
  SOUND("cacsit", sg_none,   98),
  SOUND("brssit", sg_none,   94),
  SOUND("cybsit", sg_none,   92),
  SOUND("spisit", sg_none,   90),
  SOUND("bspsit", sg_none,   90),
  SOUND("kntsit", sg_none,   90),
  SOUND("vilsit", sg_none,   90),
  SOUND("mansit", sg_none,   90),
  SOUND("pesit",  sg_none,   90),
  SOUND("sklatk", sg_none,   70),
  SOUND("sgtatk", sg_none,   70),
  SOUND("skepch", sg_none,   70),
  SOUND("vilatk", sg_none,   70),
  SOUND("claw",   sg_none,   70),
  SOUND("skeswg", sg_none,   70),
  SOUND("pldeth", sg_none,   32),
  SOUND("pdiehi", sg_none,   32),
  SOUND("podth1", sg_none,   70),
  SOUND("podth2", sg_none,   70),
  SOUND("podth3", sg_none,   70),
  SOUND("bgdth1", sg_none,   70),
  SOUND("bgdth2", sg_none,   70),
  SOUND("sgtdth", sg_none,   70),
  SOUND("cacdth", sg_none,   70),
  SOUND("skldth", sg_none,   70),
  SOUND("brsdth", sg_none,   32),
  SOUND("cybdth", sg_none,   32),
  SOUND("spidth", sg_none,   32),
  SOUND("bspdth", sg_none,   32),
  SOUND("vildth", sg_none,   32),
  SOUND("kntdth", sg_none,   32),
  SOUND("pedth",  sg_none,   32),
  SOUND("skedth", sg_none,   32),
  SOUND("posact", sg_none,  120),
  SOUND("bgact",  sg_none,  120),
  SOUND("dmact",  sg_none,  120),
  SOUND("bspact", sg_none,  100),
  SOUND("bspwlk", sg_none,  100),
  SOUND("vilact", sg_none,  100),
  SOUND("noway",  sg_oof,    78),
  SOUND("barexp", sg_none,   60),
  SOUND("punch",  sg_none,   64),
  SOUND("hoof",   sg_none,   70),
  SOUND("metal",  sg_none,   70),
  SOUND_LINK("chgun", sg_none, 64, sfx_pistol, 150),
  SOUND("tink",   sg_none,   60),
  SOUND("bdopn",  sg_none,  100),
  SOUND("bdcls",  sg_none,  100),
  SOUND("itmbk",  sg_none,  100),
  SOUND("flame",  sg_none,   32),
  SOUND("flamst", sg_none,   32),
  SOUND("getpow", sg_getpow, 60),
  SOUND("bospit", sg_none,   70),
  SOUND("boscub", sg_none,   70),
  SOUND("bossit", sg_none,   70),
  SOUND("bospn",  sg_none,   70),
  SOUND("bosdth", sg_none,   70),
  SOUND("manatk", sg_none,   70),
  SOUND("mandth", sg_none,   70),
  SOUND("sssit",  sg_none,   70),
  SOUND("ssdth",  sg_none,   70),
  SOUND("keenpn", sg_none,   70),
  SOUND("keendt", sg_none,   70),
  SOUND("skeact", sg_none,   70),
  SOUND("skesit", sg_none,   70),
  SOUND("skeatk", sg_none,   70),
  SOUND("radio",  sg_none,   60),

  // killough 11/98: dog sounds
  SOUND("dgsit",  sg_none,   98),
  SOUND("dgatk",  sg_none,   70),
  SOUND("dgact",  sg_none,  120),
  SOUND("dgdth",  sg_none,   70),
  SOUND("dgpain", sg_none,   96),

  // [crispy] play DSSECRET if available
  SOUND("secret",  sg_none,  100),

  // [FG] play sound when hitting animated floor
  SOUND("splash", sg_oof,    96),
  SOUND("ploosh", sg_oof,    96),
  SOUND("lvsiz",  sg_oof,    96),
  SOUND("splsml", sg_oof,    96),
  SOUND("plosml", sg_oof,    96),
  SOUND("lavsml", sg_oof,    96),

  [500] = SOUND("fre000", sg_none, 127),
  [501] = SOUND("fre001", sg_none, 127),
  [502] = SOUND("fre002", sg_none, 127),
  [503] = SOUND("fre003", sg_none, 127),
  [504] = SOUND("fre004", sg_none, 127),
  [505] = SOUND("fre005", sg_none, 127),
  [506] = SOUND("fre006", sg_none, 127),
  [507] = SOUND("fre007", sg_none, 127),
  [508] = SOUND("fre008", sg_none, 127),
  [509] = SOUND("fre009", sg_none, 127),
  [510] = SOUND("fre010", sg_none, 127),
  [511] = SOUND("fre011", sg_none, 127),
  [512] = SOUND("fre012", sg_none, 127),
  [513] = SOUND("fre013", sg_none, 127),
  [514] = SOUND("fre014", sg_none, 127),
  [515] = SOUND("fre015", sg_none, 127),
  [516] = SOUND("fre016", sg_none, 127),
  [517] = SOUND("fre017", sg_none, 127),
  [518] = SOUND("fre018", sg_none, 127),
  [519] = SOUND("fre019", sg_none, 127),
  [520] = SOUND("fre020", sg_none, 127),
  [521] = SOUND("fre021", sg_none, 127),
  [522] = SOUND("fre022", sg_none, 127),
  [523] = SOUND("fre023", sg_none, 127),
  [524] = SOUND("fre024", sg_none, 127),
  [525] = SOUND("fre025", sg_none, 127),
  [526] = SOUND("fre026", sg_none, 127),
  [527] = SOUND("fre027", sg_none, 127),
  [528] = SOUND("fre028", sg_none, 127),
  [529] = SOUND("fre029", sg_none, 127),
  [530] = SOUND("fre030", sg_none, 127),
  [531] = SOUND("fre031", sg_none, 127),
  [532] = SOUND("fre032", sg_none, 127),
  [533] = SOUND("fre033", sg_none, 127),
  [534] = SOUND("fre034", sg_none, 127),
  [535] = SOUND("fre035", sg_none, 127),
  [536] = SOUND("fre036", sg_none, 127),
  [537] = SOUND("fre037", sg_none, 127),
  [538] = SOUND("fre038", sg_none, 127),
  [539] = SOUND("fre039", sg_none, 127),
  [540] = SOUND("fre040", sg_none, 127),
  [541] = SOUND("fre041", sg_none, 127),
  [542] = SOUND("fre042", sg_none, 127),
  [543] = SOUND("fre043", sg_none, 127),
  [544] = SOUND("fre044", sg_none, 127),
  [545] = SOUND("fre045", sg_none, 127),
  [546] = SOUND("fre046", sg_none, 127),
  [547] = SOUND("fre047", sg_none, 127),
  [548] = SOUND("fre048", sg_none, 127),
  [549] = SOUND("fre049", sg_none, 127),
  [550] = SOUND("fre050", sg_none, 127),
  [551] = SOUND("fre051", sg_none, 127),
  [552] = SOUND("fre052", sg_none, 127),
  [553] = SOUND("fre053", sg_none, 127),
  [554] = SOUND("fre054", sg_none, 127),
  [555] = SOUND("fre055", sg_none, 127),
  [556] = SOUND("fre056", sg_none, 127),
  [557] = SOUND("fre057", sg_none, 127),
  [558] = SOUND("fre058", sg_none, 127),
  [559] = SOUND("fre059", sg_none, 127),
  [560] = SOUND("fre060", sg_none, 127),
  [561] = SOUND("fre061", sg_none, 127),
  [562] = SOUND("fre062", sg_none, 127),
  [563] = SOUND("fre063", sg_none, 127),
  [564] = SOUND("fre064", sg_none, 127),
  [565] = SOUND("fre065", sg_none, 127),
  [566] = SOUND("fre066", sg_none, 127),
  [567] = SOUND("fre067", sg_none, 127),
  [568] = SOUND("fre068", sg_none, 127),
  [569] = SOUND("fre069", sg_none, 127),
  [570] = SOUND("fre070", sg_none, 127),
  [571] = SOUND("fre071", sg_none, 127),
  [572] = SOUND("fre072", sg_none, 127),
  [573] = SOUND("fre073", sg_none, 127),
  [574] = SOUND("fre074", sg_none, 127),
  [575] = SOUND("fre075", sg_none, 127),
  [576] = SOUND("fre076", sg_none, 127),
  [577] = SOUND("fre077", sg_none, 127),
  [578] = SOUND("fre078", sg_none, 127),
  [579] = SOUND("fre079", sg_none, 127),
  [580] = SOUND("fre080", sg_none, 127),
  [581] = SOUND("fre081", sg_none, 127),
  [582] = SOUND("fre082", sg_none, 127),
  [583] = SOUND("fre083", sg_none, 127),
  [584] = SOUND("fre084", sg_none, 127),
  [585] = SOUND("fre085", sg_none, 127),
  [586] = SOUND("fre086", sg_none, 127),
  [587] = SOUND("fre087", sg_none, 127),
  [588] = SOUND("fre088", sg_none, 127),
  [589] = SOUND("fre089", sg_none, 127),
  [590] = SOUND("fre090", sg_none, 127),
  [591] = SOUND("fre091", sg_none, 127),
  [592] = SOUND("fre092", sg_none, 127),
  [593] = SOUND("fre093", sg_none, 127),
  [594] = SOUND("fre094", sg_none, 127),
  [595] = SOUND("fre095", sg_none, 127),
  [596] = SOUND("fre096", sg_none, 127),
  [597] = SOUND("fre097", sg_none, 127),
  [598] = SOUND("fre098", sg_none, 127),
  [599] = SOUND("fre099", sg_none, 127),
  [600] = SOUND("fre100", sg_none, 127),
  [601] = SOUND("fre101", sg_none, 127),
  [602] = SOUND("fre102", sg_none, 127),
  [603] = SOUND("fre103", sg_none, 127),
  [604] = SOUND("fre104", sg_none, 127),
  [605] = SOUND("fre105", sg_none, 127),
  [606] = SOUND("fre106", sg_none, 127),
  [607] = SOUND("fre107", sg_none, 127),
  [608] = SOUND("fre108", sg_none, 127),
  [609] = SOUND("fre109", sg_none, 127),
  [610] = SOUND("fre110", sg_none, 127),
  [611] = SOUND("fre111", sg_none, 127),
  [612] = SOUND("fre112", sg_none, 127),
  [613] = SOUND("fre113", sg_none, 127),
  [614] = SOUND("fre114", sg_none, 127),
  [615] = SOUND("fre115", sg_none, 127),
  [616] = SOUND("fre116", sg_none, 127),
  [617] = SOUND("fre117", sg_none, 127),
  [618] = SOUND("fre118", sg_none, 127),
  [619] = SOUND("fre119", sg_none, 127),
  [620] = SOUND("fre120", sg_none, 127),
  [621] = SOUND("fre121", sg_none, 127),
  [622] = SOUND("fre122", sg_none, 127),
  [623] = SOUND("fre123", sg_none, 127),
  [624] = SOUND("fre124", sg_none, 127),
  [625] = SOUND("fre125", sg_none, 127),
  [626] = SOUND("fre126", sg_none, 127),
  [627] = SOUND("fre127", sg_none, 127),
  [628] = SOUND("fre128", sg_none, 127),
  [629] = SOUND("fre129", sg_none, 127),
  [630] = SOUND("fre130", sg_none, 127),
  [631] = SOUND("fre131", sg_none, 127),
  [632] = SOUND("fre132", sg_none, 127),
  [633] = SOUND("fre133", sg_none, 127),
  [634] = SOUND("fre134", sg_none, 127),
  [635] = SOUND("fre135", sg_none, 127),
  [636] = SOUND("fre136", sg_none, 127),
  [637] = SOUND("fre137", sg_none, 127),
  [638] = SOUND("fre138", sg_none, 127),
  [639] = SOUND("fre139", sg_none, 127),
  [640] = SOUND("fre140", sg_none, 127),
  [641] = SOUND("fre141", sg_none, 127),
  [642] = SOUND("fre142", sg_none, 127),
  [643] = SOUND("fre143", sg_none, 127),
  [644] = SOUND("fre144", sg_none, 127),
  [645] = SOUND("fre145", sg_none, 127),
  [646] = SOUND("fre146", sg_none, 127),
  [647] = SOUND("fre147", sg_none, 127),
  [648] = SOUND("fre148", sg_none, 127),
  [649] = SOUND("fre149", sg_none, 127),
  [650] = SOUND("fre150", sg_none, 127),
  [651] = SOUND("fre151", sg_none, 127),
  [652] = SOUND("fre152", sg_none, 127),
  [653] = SOUND("fre153", sg_none, 127),
  [654] = SOUND("fre154", sg_none, 127),
  [655] = SOUND("fre155", sg_none, 127),
  [656] = SOUND("fre156", sg_none, 127),
  [657] = SOUND("fre157", sg_none, 127),
  [658] = SOUND("fre158", sg_none, 127),
  [659] = SOUND("fre159", sg_none, 127),
  [660] = SOUND("fre160", sg_none, 127),
  [661] = SOUND("fre161", sg_none, 127),
  [662] = SOUND("fre162", sg_none, 127),
  [663] = SOUND("fre163", sg_none, 127),
  [664] = SOUND("fre164", sg_none, 127),
  [665] = SOUND("fre165", sg_none, 127),
  [666] = SOUND("fre166", sg_none, 127),
  [667] = SOUND("fre167", sg_none, 127),
  [668] = SOUND("fre168", sg_none, 127),
  [669] = SOUND("fre169", sg_none, 127),
  [670] = SOUND("fre170", sg_none, 127),
  [671] = SOUND("fre171", sg_none, 127),
  [672] = SOUND("fre172", sg_none, 127),
  [673] = SOUND("fre173", sg_none, 127),
  [674] = SOUND("fre174", sg_none, 127),
  [675] = SOUND("fre175", sg_none, 127),
  [676] = SOUND("fre176", sg_none, 127),
  [677] = SOUND("fre177", sg_none, 127),
  [678] = SOUND("fre178", sg_none, 127),
  [679] = SOUND("fre179", sg_none, 127),
  [680] = SOUND("fre180", sg_none, 127),
  [681] = SOUND("fre181", sg_none, 127),
  [682] = SOUND("fre182", sg_none, 127),
  [683] = SOUND("fre183", sg_none, 127),
  [684] = SOUND("fre184", sg_none, 127),
  [685] = SOUND("fre185", sg_none, 127),
  [686] = SOUND("fre186", sg_none, 127),
  [687] = SOUND("fre187", sg_none, 127),
  [688] = SOUND("fre188", sg_none, 127),
  [689] = SOUND("fre189", sg_none, 127),
  [690] = SOUND("fre190", sg_none, 127),
  [691] = SOUND("fre191", sg_none, 127),
  [692] = SOUND("fre192", sg_none, 127),
  [693] = SOUND("fre193", sg_none, 127),
  [694] = SOUND("fre194", sg_none, 127),
  [695] = SOUND("fre195", sg_none, 127),
  [696] = SOUND("fre196", sg_none, 127),
  [697] = SOUND("fre197", sg_none, 127),
  [698] = SOUND("fre198", sg_none, 127),
  [699] = SOUND("fre199", sg_none, 127),
};

//----------------------------------------------------------------------------
//
// $Log: sounds.c,v $
// Revision 1.3  1998/05/03  22:44:25  killough
// beautification
//
// Revision 1.2  1998/01/26  19:24:54  phares
// First rev with no ^Ms
//
// Revision 1.1.1.1  1998/01/19  14:03:03  rand
// Lee's Jan 19 sources
//
//----------------------------------------------------------------------------
