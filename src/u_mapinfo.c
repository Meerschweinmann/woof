//-----------------------------------------------------------------------------
//
// Copyright 2017 Christoph Oelckers
// Copyright 2019 Fernando Carmona Varo
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/
//
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>

#include "doomdef.h"
#include "doomstat.h"
#include "doomtype.h"
#include "m_array.h"
#include "m_misc.h"
#include "m_scanner.h"
#include "u_mapinfo.h"
#include "w_wad.h"
#include "z_zone.h"

void M_AddEpisode(const char *map, const char *gfx, const char *txt, char key);
void M_ClearEpisodes(void);

int G_ValidateMapName(const char *mapname, int *pEpi, int *pMap);

mapentry_t *umapinfo = NULL, *umapdef = NULL;

static level_t *secretlevels;

static const char *const actor_names[] =
{
    "DoomPlayer", "ZombieMan", "ShotgunGuy", "Archvile", "ArchvileFire",
    "Revenant", "RevenantTracer", "RevenantTracerSmoke", "Fatso", "FatShot",
    "ChaingunGuy", "DoomImp", "Demon", "Spectre", "Cacodemon", "BaronOfHell",
    "BaronBall", "HellKnight", "LostSoul", "SpiderMastermind", "Arachnotron",
    "Cyberdemon", "PainElemental", "WolfensteinSS", "CommanderKeen",
    "BossBrain", "BossEye", "BossTarget", "SpawnShot", "SpawnFire",
    "ExplosiveBarrel", "DoomImpBall", "CacodemonBall", "Rocket", "PlasmaBall",
    "BFGBall", "ArachnotronPlasma", "BulletPuff", "Blood", "TeleportFog",
    "ItemFog", "TeleportDest", "BFGExtra", "GreenArmor", "BlueArmor",
    "HealthBonus", "ArmorBonus", "BlueCard", "RedCard", "YellowCard",
    "YellowSkull", "RedSkull", "BlueSkull", "Stimpack", "Medikit", "Soulsphere",
    "InvulnerabilitySphere", "Berserk", "BlurSphere", "RadSuit", "Allmap",
    "Infrared", "Megasphere", "Clip", "ClipBox", "RocketAmmo", "RocketBox",
    "Cell", "CellPack", "Shell", "ShellBox", "Backpack", "BFG9000", "Chaingun",
    "Chainsaw", "RocketLauncher", "PlasmaRifle", "Shotgun", "SuperShotgun",
    "TechLamp", "TechLamp2", "Column", "TallGreenColumn", "ShortGreenColumn",
    "TallRedColumn", "ShortRedColumn", "SkullColumn", "HeartColumn", "EvilEye",
    "FloatingSkull", "TorchTree", "BlueTorch", "GreenTorch", "RedTorch",
    "ShortBlueTorch", "ShortGreenTorch", "ShortRedTorch", "Stalagtite",
    "TechPillar", "CandleStick", "Candelabra", "BloodyTwitch", "Meat2", "Meat3",
    "Meat4", "Meat5", "NonsolidMeat2", "NonsolidMeat4", "NonsolidMeat3",
    "NonsolidMeat5", "NonsolidTwitch", "DeadCacodemon", "DeadMarine",
    "DeadZombieMan", "DeadDemon", "DeadLostSoul", "DeadDoomImp",
    "DeadShotgunGuy", "GibbedMarine", "GibbedMarineExtra", "HeadsOnAStick",
    "Gibs", "HeadOnAStick", "HeadCandles", "DeadStick", "LiveStick", "BigTree",
    "BurningBarrel", "HangNoGuts", "HangBNoBrain", "HangTLookingDown",
    "HangTSkull", "HangTLookingUp", "HangTNoBrain", "ColonGibs",
    "SmallBloodPool", "BrainStem",
    // Boom/MBF additions
    "PointPusher", "PointPuller", "MBFHelperDog", "PlasmaBall1", "PlasmaBall2",
    "EvilSceptre", "UnholyBible", "MusicChanger", "Deh_Actor_145",
    "Deh_Actor_146", "Deh_Actor_147", "Deh_Actor_148", "Deh_Actor_149",
    // DEHEXTRA Actors start here
    "Deh_Actor_150", // Extra thing 0
    "Deh_Actor_151", // Extra thing 1
    "Deh_Actor_152", // Extra thing 2
    "Deh_Actor_153", // Extra thing 3
    "Deh_Actor_154", // Extra thing 4
    "Deh_Actor_155", // Extra thing 5
    "Deh_Actor_156", // Extra thing 6
    "Deh_Actor_157", // Extra thing 7
    "Deh_Actor_158", // Extra thing 8
    "Deh_Actor_159", // Extra thing 9
    "Deh_Actor_160", // Extra thing 10
    "Deh_Actor_161", // Extra thing 11
    "Deh_Actor_162", // Extra thing 12
    "Deh_Actor_163", // Extra thing 13
    "Deh_Actor_164", // Extra thing 14
    "Deh_Actor_165", // Extra thing 15
    "Deh_Actor_166", // Extra thing 16
    "Deh_Actor_167", // Extra thing 17
    "Deh_Actor_168", // Extra thing 18
    "Deh_Actor_169", // Extra thing 19
    "Deh_Actor_170", // Extra thing 20
    "Deh_Actor_171", // Extra thing 21
    "Deh_Actor_172", // Extra thing 22
    "Deh_Actor_173", // Extra thing 23
    "Deh_Actor_174", // Extra thing 24
    "Deh_Actor_175", // Extra thing 25
    "Deh_Actor_176", // Extra thing 26
    "Deh_Actor_177", // Extra thing 27
    "Deh_Actor_178", // Extra thing 28
    "Deh_Actor_179", // Extra thing 29
    "Deh_Actor_180", // Extra thing 30
    "Deh_Actor_181", // Extra thing 31
    "Deh_Actor_182", // Extra thing 32
    "Deh_Actor_183", // Extra thing 33
    "Deh_Actor_184", // Extra thing 34
    "Deh_Actor_185", // Extra thing 35
    "Deh_Actor_186", // Extra thing 36
    "Deh_Actor_187", // Extra thing 37
    "Deh_Actor_188", // Extra thing 38
    "Deh_Actor_189", // Extra thing 39
    "Deh_Actor_190", // Extra thing 40
    "Deh_Actor_191", // Extra thing 41
    "Deh_Actor_192", // Extra thing 42
    "Deh_Actor_193", // Extra thing 43
    "Deh_Actor_194", // Extra thing 44
    "Deh_Actor_195", // Extra thing 45
    "Deh_Actor_196", // Extra thing 46
    "Deh_Actor_197", // Extra thing 47
    "Deh_Actor_198", // Extra thing 48
    "Deh_Actor_199", // Extra thing 49
    "Deh_Actor_200", // Extra thing 50
    "Deh_Actor_201", // Extra thing 51
    "Deh_Actor_202", // Extra thing 52
    "Deh_Actor_203", // Extra thing 53
    "Deh_Actor_204", // Extra thing 54
    "Deh_Actor_205", // Extra thing 55
    "Deh_Actor_206", // Extra thing 56
    "Deh_Actor_207", // Extra thing 57
    "Deh_Actor_208", // Extra thing 58
    "Deh_Actor_209", // Extra thing 59
    "Deh_Actor_210", // Extra thing 60
    "Deh_Actor_211", // Extra thing 61
    "Deh_Actor_212", // Extra thing 62
    "Deh_Actor_213", // Extra thing 63
    "Deh_Actor_214", // Extra thing 64
    "Deh_Actor_215", // Extra thing 65
    "Deh_Actor_216", // Extra thing 66
    "Deh_Actor_217", // Extra thing 67
    "Deh_Actor_218", // Extra thing 68
    "Deh_Actor_219", // Extra thing 69
    "Deh_Actor_220", // Extra thing 70
    "Deh_Actor_221", // Extra thing 71
    "Deh_Actor_222", // Extra thing 72
    "Deh_Actor_223", // Extra thing 73
    "Deh_Actor_224", // Extra thing 74
    "Deh_Actor_225", // Extra thing 75
    "Deh_Actor_226", // Extra thing 76
    "Deh_Actor_227", // Extra thing 77
    "Deh_Actor_228", // Extra thing 78
    "Deh_Actor_229", // Extra thing 79
    "Deh_Actor_230", // Extra thing 80
    "Deh_Actor_231", // Extra thing 81
    "Deh_Actor_232", // Extra thing 82
    "Deh_Actor_233", // Extra thing 83
    "Deh_Actor_234", // Extra thing 84
    "Deh_Actor_235", // Extra thing 85
    "Deh_Actor_236", // Extra thing 86
    "Deh_Actor_237", // Extra thing 87
    "Deh_Actor_238", // Extra thing 88
    "Deh_Actor_239", // Extra thing 89
    "Deh_Actor_240", // Extra thing 90
    "Deh_Actor_241", // Extra thing 91
    "Deh_Actor_242", // Extra thing 92
    "Deh_Actor_243", // Extra thing 93
    "Deh_Actor_244", // Extra thing 94
    "Deh_Actor_245", // Extra thing 95
    "Deh_Actor_246", // Extra thing 96
    "Deh_Actor_247", // Extra thing 97
    "Deh_Actor_248", // Extra thing 98
    "Deh_Actor_249", // Extra thing 99
};

static void FreeMap(mapentry_t *mape)
{
    if (mape->mapname)
    {
        free(mape->mapname);
    }
    if (mape->levelname)
    {
        free(mape->levelname);
    }
    if (mape->label)
    {
        free(mape->label);
    }
    if (mape->intertext)
    {
        free(mape->intertext);
    }
    if (mape->intertextsecret)
    {
        free(mape->intertextsecret);
    }
    if (mape->author)
    {
        free(mape->author);
    }
    memset(mape, 0, sizeof(*mape));
}

static void ReplaceString(char **pptr, const char *newstring)
{
    if (*pptr != NULL)
    {
        free(*pptr);
    }
    *pptr = M_StringDuplicate(newstring);
}

static void UpdateMapEntry(mapentry_t *mape, mapentry_t *newe)
{
    if (newe->mapname)
    {
        ReplaceString(&mape->mapname, newe->mapname);
    }
    if (newe->levelname)
    {
        ReplaceString(&mape->levelname, newe->levelname);
    }
    if (newe->label)
    {
        ReplaceString(&mape->label, newe->label);
    }
    if (newe->author)
    {
        ReplaceString(&mape->author, newe->author);
    }
    if (newe->intertext)
    {
        ReplaceString(&mape->intertext, newe->intertext);
    }
    if (newe->intertextsecret)
    {
        ReplaceString(&mape->intertextsecret, newe->intertextsecret);
    }
    if (newe->levelpic[0])
    {
        strcpy(mape->levelpic, newe->levelpic);
    }
    if (newe->nextmap[0])
    {
        strcpy(mape->nextmap, newe->nextmap);
    }
    if (newe->nextsecret[0])
    {
        strcpy(mape->nextsecret, newe->nextsecret);
    }
    if (newe->music[0])
    {
        strcpy(mape->music, newe->music);
    }
    if (newe->skytexture[0])
    {
        strcpy(mape->skytexture, newe->skytexture);
    }
    if (newe->endpic[0])
    {
        strcpy(mape->endpic, newe->endpic);
    }
    if (newe->exitpic[0])
    {
        strcpy(mape->exitpic, newe->exitpic);
    }
    if (newe->enterpic[0])
    {
        strcpy(mape->enterpic, newe->enterpic);
    }
    if (newe->exitanim[0])
    {
        strcpy(mape->exitanim, newe->exitanim);
    }
    if (newe->enteranim[0])
    {
        strcpy(mape->enteranim, newe->enteranim);
    }
    if (newe->interbackdrop[0])
    {
        strcpy(mape->interbackdrop, newe->interbackdrop);
    }
    if (newe->intermusic[0])
    {
        strcpy(mape->intermusic, newe->intermusic);
    }
    if (newe->partime)
    {
        mape->partime = newe->partime;
    }
    if (newe->nointermission)
    {
        mape->nointermission = newe->nointermission;
    }
    if (array_size(newe->bossactions))
    {
        if (mape->bossactions)
        {
            array_free(mape->bossactions);
        }
        mape->bossactions = newe->bossactions;
    }
}

// -----------------------------------------------
// Parses a set of string and concatenates them
// Returns a pointer to the string (must be freed)
// -----------------------------------------------
static char *ParseMultiString(scanner_t *s)
{
    char *build = NULL;

    if (SC_CheckToken(s, TK_Identifier))
    {
        if (!strcasecmp(SC_GetString(s), "clear"))
        {
            // this was explicitly deleted to override the default.
            return strdup("-");
        }
        else
        {
            SC_Error(s, "Either 'clear' or string constant expected");
        }
    }

    do
    {
        SC_MustGetToken(s, TK_StringConst);
        if (build == NULL)
        {
            build = M_StringDuplicate(SC_GetString(s));
        }
        else
        {
            char *tmp = build;
            build = M_StringJoin(tmp, "\n", SC_GetString(s));
            free(tmp);
        }
    } while (SC_CheckToken(s, ','));

    return build;
}

// Parses a lump name. The buffer must be at least 9 characters.

static void ParseLumpName(scanner_t *s, char *buffer)
{
    SC_MustGetToken(s, TK_StringConst);
    if (strlen(SC_GetString(s)) > 8)
    {
        SC_Error(s, "String too long. Maximum size is 8 characters.");
    }
    strncpy(buffer, SC_GetString(s), 8);
    buffer[8] = 0;
    M_StringToUpper(buffer);
}

// Parses a standard property that is already known
// These do not get stored in the property list
// but in dedicated struct member variables.

static void ParseStandardProperty(scanner_t *s, mapentry_t *mape)
{
    SC_MustGetToken(s, TK_Identifier);
    char *prop = M_StringDuplicate(SC_GetString(s));

    SC_MustGetToken(s, '=');
    if (!strcasecmp(prop, "levelname"))
    {
        SC_MustGetToken(s, TK_StringConst);
        ReplaceString(&mape->levelname, SC_GetString(s));
    }
    else if (!strcasecmp(prop, "label"))
    {
        if (SC_CheckToken(s, TK_Identifier))
        {
            if (!strcasecmp(SC_GetString(s), "clear"))
            {
                ReplaceString(&mape->label, "-");
            }
            else
            {
                SC_Error(s, "Either 'clear' or string constant expected");
            }
        }
        else
        {
            SC_MustGetToken(s, TK_StringConst);
            ReplaceString(&mape->label, SC_GetString(s));
        }
    }
    else if (!strcasecmp(prop, "author"))
    {
        SC_MustGetToken(s, TK_StringConst);
        ReplaceString(&mape->author, SC_GetString(s));
    }
    else if (!strcasecmp(prop, "episode"))
    {
        if (SC_CheckToken(s, TK_Identifier))
        {
            if (!strcasecmp(SC_GetString(s), "clear"))
            {
                M_ClearEpisodes();
            }
            else
            {
                SC_Error(s, "Either 'clear' or string constant expected");
            }
        }
        else
        {
            char lumpname[9] = {0};
            char *alttext = NULL;
            char key = 0;

            ParseLumpName(s, lumpname);
            if (SC_CheckToken(s, ','))
            {
                SC_MustGetToken(s, TK_StringConst);
                alttext = M_StringDuplicate(SC_GetString(s));
                if (SC_CheckToken(s, ','))
                {
                    SC_MustGetToken(s, TK_StringConst);
                    const char *tmp = SC_GetString(s);
                    key = M_ToLower(tmp[0]);
                }
            }

            M_AddEpisode(mape->mapname, lumpname, alttext, key);

            if (alttext)
            {
                free(alttext);
            }
        }
    }
    else if (!strcasecmp(prop, "next"))
    {
        ParseLumpName(s, mape->nextmap);
        if (!G_ValidateMapName(mape->nextmap, NULL, NULL))
        {
            SC_Error(s, "Invalid map name %s.", mape->nextmap);
        }
    }
    else if (!strcasecmp(prop, "nextsecret"))
    {
        ParseLumpName(s, mape->nextsecret);
        level_t level = {0};
        if (!G_ValidateMapName(mape->nextsecret, &level.episode, &level.map))
        {
            SC_Error(s, "Invalid map name %s", mape->nextsecret);
        }
        array_push(secretlevels, level);
    }
    else if (!strcasecmp(prop, "levelpic"))
    {
        ParseLumpName(s, mape->levelpic);
    }
    else if (!strcasecmp(prop, "skytexture"))
    {
        ParseLumpName(s, mape->skytexture);
    }
    else if (!strcasecmp(prop, "music"))
    {
        ParseLumpName(s, mape->music);
    }
    else if (!strcasecmp(prop, "endpic"))
    {
        ParseLumpName(s, mape->endpic);
    }
    else if (!strcasecmp(prop, "endcast"))
    {
        SC_MustGetToken(s, TK_BoolConst);
        if (SC_GetBoolean(s))
        {
            strcpy(mape->endpic, "$CAST");
        }
        else
        {
            strcpy(mape->endpic, "-");
        }
    }
    else if (!strcasecmp(prop, "endbunny"))
    {
        SC_MustGetToken(s, TK_BoolConst);
        if (SC_GetBoolean(s))
        {
            strcpy(mape->endpic, "$BUNNY");
        }
        else
        {
            strcpy(mape->endpic, "-");
        }
    }
    else if (!strcasecmp(prop, "endgame"))
    {
        SC_MustGetToken(s, TK_BoolConst);
        if (SC_GetBoolean(s))
        {
            strcpy(mape->endpic, "!");
        }
        else
        {
            strcpy(mape->endpic, "-");
        }
    }
    else if (!strcasecmp(prop, "exitpic"))
    {
        ParseLumpName(s, mape->exitpic);
    }
    else if (!strcasecmp(prop, "enterpic"))
    {
        ParseLumpName(s, mape->enterpic);
    }
    else if (!strcasecmp(prop, "exitanim"))
    {
        ParseLumpName(s, mape->exitanim);
    }
    else if (!strcasecmp(prop, "enteranim"))
    {
        ParseLumpName(s, mape->enteranim);
    }
    else if (!strcasecmp(prop, "nointermission"))
    {
        SC_MustGetToken(s, TK_BoolConst);
        mape->nointermission = SC_GetBoolean(s);
    }
    else if (!strcasecmp(prop, "partime"))
    {
        SC_MustGetToken(s, TK_IntConst);
        mape->partime = SC_GetNumber(s);
    }
    else if (!strcasecmp(prop, "intertext"))
    {
        char *text = ParseMultiString(s);
        if (mape->intertext)
        {
            free(mape->intertext);
        }
        mape->intertext = text;
    }
    else if (!strcasecmp(prop, "intertextsecret"))
    {
        char *text = ParseMultiString(s);
        if (mape->intertextsecret)
        {
            free(mape->intertextsecret);
        }
        mape->intertextsecret = text;
    }
    else if (!strcasecmp(prop, "interbackdrop"))
    {
        ParseLumpName(s, mape->interbackdrop);
    }
    else if (!strcasecmp(prop, "intermusic"))
    {
        ParseLumpName(s, mape->intermusic);
    }
    else if (!strcasecmp(prop, "bossaction"))
    {
        SC_MustGetToken(s, TK_Identifier);
        if (!strcasecmp(SC_GetString(s), "clear"))
        {
            array_free(mape->bossactions);
            mape->nobossactions = true; // mark level free of boss actions
        }
        else
        {
            int i, special, tag;
            for (i = 0; arrlen(actor_names); i++)
            {
                if (!strcasecmp(SC_GetString(s), actor_names[i]))
                {
                    break;
                }
            }
            if (i == arrlen(actor_names))
            {
                SC_Error(s, "bossaction: unknown thing type '%s'",
                         SC_GetString(s));
            }
            SC_MustGetToken(s, ',');
            SC_MustGetToken(s, TK_IntConst);
            special = SC_GetNumber(s);
            SC_MustGetToken(s, ',');
            SC_MustGetToken(s, TK_IntConst);
            tag = SC_GetNumber(s);
            // allow no 0-tag specials here, unless a level exit.
            if (tag != 0 || special == 11 || special == 51 || special == 52
                || special == 124)
            {
                bossaction_t bossaction = {i, special, tag};
                array_push(mape->bossactions, bossaction);
            }
        }
    }
    // If no known property name was given, skip all comma-separated values
    // after the = sign
    else
    {
        do
        {
            SC_GetNextToken(s, true);
        } while (SC_CheckToken(s, ','));
    }

    free(prop);
}

static void ParseMapEntry(scanner_t *s, mapentry_t *entry)
{
    SC_MustGetToken(s, TK_Identifier);
    if (strcasecmp(SC_GetString(s), "map"))
    {
        SC_Error(s, "Expected 'map' but got '%s' instead", SC_GetString(s));
    }

    SC_MustGetToken(s, TK_Identifier);
    if (!G_ValidateMapName(SC_GetString(s), NULL, NULL))
    {
        SC_Error(s, "Invalid map name %s", SC_GetString(s));
    }
    ReplaceString(&entry->mapname, SC_GetString(s));

    SC_MustGetToken(s, '{');
    while (!SC_CheckToken(s, '}'))
    {
        ParseStandardProperty(s, entry);
    }
}

// -----------------------------------------------
//
// Parses a complete UMAPINFO lump
//
// -----------------------------------------------

static void SetDefaults(mapentry_t *entry, const char *mapname)
{
    mapentry_t *default_entry;
    array_foreach(default_entry, umapdef)
    {
        if (!strcmp(mapname, default_entry->mapname))
        {
            UpdateMapEntry(entry, default_entry);
            break;
        }
    }
}

void U_ParseMapDefInfo(int lumpnum)
{
    scanner_t *s = SC_Open("UMAPDEF", W_CacheLumpNum(lumpnum, PU_CACHE),
                           W_LumpLength(lumpnum));
    while (SC_TokensLeft(s))
    {
        mapentry_t parsed = {0};
        ParseMapEntry(s, &parsed);
        array_push(umapdef, parsed);
    }
    SC_Close(s);
}

void U_ParseMapInfo(int lumpnum)
{
    scanner_t *s = SC_Open("UMAPINFO", W_CacheLumpNum(lumpnum, PU_CACHE),
                           W_LumpLength(lumpnum));
    while (SC_TokensLeft(s))
    {
        mapentry_t parsed = {0};
        ParseMapEntry(s, &parsed);

        // Set default level progression here to simplify the checks elsewhere.
        // Doing this lets us skip all normal code for this if nothing has been
        // defined.
        if (parsed.endpic[0] && (strcmp(parsed.endpic, "-") != 0))
        {
            parsed.nextmap[0] = 0;
        }
        else if (!parsed.nextmap[0] && !parsed.endpic[0])
        {
            if (!strcasecmp(parsed.mapname, "MAP30"))
            {
                strcpy(parsed.endpic, "$CAST");
            }
            else if (!strcasecmp(parsed.mapname, "E1M8"))
            {
                strcpy(parsed.endpic, gamemode == retail ? "CREDIT" : "HELP2");
            }
            else if (!strcasecmp(parsed.mapname, "E2M8"))
            {
                strcpy(parsed.endpic, "VICTORY2");
            }
            else if (!strcasecmp(parsed.mapname, "E3M8"))
            {
                strcpy(parsed.endpic, "$BUNNY");
            }
            else if (!strcasecmp(parsed.mapname, "E4M8"))
            {
                strcpy(parsed.endpic, "ENDPIC");
            }
            else
            {
                int ep, map;
                G_ValidateMapName(parsed.mapname, &ep, &map);
                strcpy(parsed.nextmap, MapName(ep, map + 1));
            }
        }

        // Does this entry already exist? If yes, replace it.
        mapentry_t *entry;
        array_foreach(entry, umapinfo)
        {
            if (!strcmp(parsed.mapname, entry->mapname))
            {
                FreeMap(entry);
                SetDefaults(entry, parsed.mapname);
                UpdateMapEntry(entry, &parsed);
                break;
            }
        }
        // Not found so create a new one.
        if (entry == array_end(umapinfo))
        {
            mapentry_t new = {0};
            SetDefaults(&new, parsed.mapname);
            UpdateMapEntry(&new, &parsed);
            array_push(umapinfo, new);
        }
    }

    SC_Close(s);
}

boolean U_CheckField(char *str)
{
    return str && str[0] && strcmp(str, "-");
}

boolean U_IsSecretMap(int episode, int map)
{
    level_t *level;
    array_foreach(level, secretlevels)
    {
        if (level->episode == episode && level->map == map)
        {
            return true;
        }
    }
    return false;
}
