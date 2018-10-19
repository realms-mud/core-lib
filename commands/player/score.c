//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/include/itemFormatters.h"

private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Player Information";
        addCommandTemplate("score [-v]");
        addCommandTemplate("? [-v]"); 

        Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string overallLevel(object initiator,
    string colorConfiguration, int useUnicode)
{
    string format = " \x1b[0;36mOverall Level:\x1b[0m \x1b[0;32m%-22s\x1b[0m\x1b[0;31m|\x1b[0m\n";

    string level = initiator->isRealizationOf("wizard") ?
        capitalize(initiator->wizardLevel()) :
        to_string(initiator->effectiveLevel());

    return configuration->decorate("Overall Level: ", "content", "score",
            colorConfiguration) +
        configuration->decorate(sprintf("%-21s", level), "value", "score",
            colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string raceDetails(object initiator,
    string colorConfiguration, int useUnicode)
{
    object raceDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    return configuration->decorate("Race: ", "content", "score",
            colorConfiguration) +
        configuration->decorate(sprintf("%-33s",
            raceDictionary->raceDetails(initiator)), "value", "score",
            colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string combatStatistics(object initiator,
    string colorConfiguration, int useUnicode)
{
    mapping bestKill = initiator->getBestKill();
    string bestKillLine;
    if (sizeof(bestKill))
    {
        bestKillLine = sprintf("\x1b[0;36mBest Kill: \x1b[0m\x1b[0;33m%s \x1b[0;35m(Level %s)\x1b[0m "
            "\x1b[0;31;1mwas killed %s times.\x1b[0m", bestKill["name"],
            bestKill["level"], bestKill["times killed"]);
    }
    else
    {
        bestKillLine = "\x1b[0;36mBest Kill: \x1b[0m\x1b[0;33m<nobody>\x1b[0;35m\x1b[0m\x1b[0;31;1m.\x1b[0m";
    }

    mapping nemesis = initiator->getNemesis();
    string nemesisLine;
    if (sizeof(nemesis))
    {
        nemesisLine = sprintf("\x1b[0;36mNemesis: \x1b[0m\x1b[0;33m%s \x1b[0;35m(Level %s)\x1b[0m "
            "\x1b[0;31;1mwas killed %s times.\x1b[0m", nemesis["name"],
            nemesis["level"], nemesis["times killed"]);
    }
    else
    {
        nemesisLine  = "\x1b[0;36mNemesis: \x1b[0m\x1b[0;33m<nobody>\x1b[0;35m\x1b[0m\x1b[0;31;1m.\x1b[0m";
    }

    return Dictionary->buildBanner(initiator->colorConfiguration(), initiator->charsetConfiguration() == "unicode", "center", "Combat Statistics") +
        sprintf("\x1b[0;31m|\x1b[0m %-117s \x1b[0;31m|\x1b[0m\n", bestKillLine) +
        sprintf("\x1b[0;31m|\x1b[0m %-117s \x1b[0;31m|\x1b[0m\n", nemesisLine);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getWeaponData(object initiator, object weapon, 
    int isPrimary, string colorConfiguration, int useUnicode)
{
    string location = isPrimary ? "Primary" : "Offhand";

    string name = weapon->query("short");
    if (sizeof(name) > 15)
    {
        name = name[0..11] + "...";
    }
    int attack = initiator->calculateAttack(0, weapon, 1);
    int damage = initiator->calculateDamage(weapon, "physical", 1);
    if (!damage)
    {
        damage = 1;
    }

    return Dictionary->banneredContent(colorConfiguration, useUnicode, 
        configuration->decorate(sprintf("%s Weapon: ", location),
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%-15s",
            weapon->query("short") ? name : "No Weapon"), "weapon", "score",
            colorConfiguration) +
        configuration->decorate(" Attack: ", "content", "score",
            colorConfiguration) +
        configuration->decorate(sprintf("%3d to %-4d", attack - 25, attack + 75),
            "weapon", "score", colorConfiguration) +
        configuration->decorate("      Damage: ", "content", "score",
            colorConfiguration) +
        configuration->decorate(sprintf("%3d to %-3d", 
            to_int(damage * 7.0 / 8.0), to_int(damage * 9.0 / 8.0)),
            "weapon", "score", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDefensiveStats(object initiator,
    string colorConfiguration, int useUnicode)
{
    string format = "\x1b[0;36m%s: \x1b[0m\x1b[0;33m%d to %d\x1b[0m";
    string row = "\x1b[0;31m|\x1b[0m  %-54s %-38s %-46s \x1b[0;31m|\x1b[0m\n";

    int defend = initiator->calculateDefendAttack();
    int soak = initiator->calculateSoakDamage("physical");

    return Dictionary->banneredContent(colorConfiguration, useUnicode,
        configuration->decorate(" Defend Attack: ",
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%3d to %-4d",
            defend - abs(defend / 2), defend),
            "weapon", "score", colorConfiguration) +
        configuration->decorate("       Soak: ",
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%3d to %-4d",
            soak - abs(soak / 2), soak),
            "weapon", "score", colorConfiguration) +
        configuration->decorate("Encumberance: ",
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%3d%7s",
            initiator->inventoryGetEncumberance(), ""),
            "weapon", "score", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCombatData(object initiator,
    string colorConfiguration, int useUnicode)
{
    string ret = "";

    object materialsDictionary =
        load_object("/lib/dictionaries/materialsDictionary.c");

    object nullEquipment =
        load_object("/lib/items/equipment.c");

    object primaryWeapon = initiator->equipmentInSlot("wielded primary");
    if (!primaryWeapon)
    {
        primaryWeapon = nullEquipment;
    }
    object offhandWeapon = initiator->equipmentInSlot("wielded offhand");

    ret += getWeaponData(initiator, primaryWeapon, 1, colorConfiguration, 
        useUnicode);

    if (offhandWeapon)
    {
        ret += getWeaponData(initiator, offhandWeapon, 0, colorConfiguration, 
            useUnicode);
    }

    ret += getDefensiveStats(initiator, colorConfiguration, useUnicode);

    string hostiles = initiator->getHostileList();
    if (sizeof(hostiles) > 35)
    {
        hostiles = hostiles[0..31] + "...";
    }
    ret += Dictionary->banneredContent(colorConfiguration, useUnicode,
        configuration->decorate(sprintf("%14s: ", "Wimpy"),
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%3d%%",
            initiator->Wimpy(0, 1)),
            "weapon", "score", colorConfiguration) +
        configuration->decorate(sprintf("%18s: ","Hunted by"),
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%-35s", hostiles),
            "weapon", "score", colorConfiguration)); 

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getBiologicalDetails(object initiator,
    string colorConfiguration, int useUnicode)
{
    string ret = "normal.  (Yeah, right)";
    string *factors = ({});

    if (initiator->Intoxicated())
    {
        factors += ({ "drunk" });
    }
    if (initiator->Drugged())
    {
        factors += ({ "drugged" });
    }
    if (initiator->Stuffed())
    {
        factors += ({ "stuffed" });
    }
    if (initiator->Soaked())
    {
        factors += ({ "soaked" });
    }
    if (sizeof(factors))
    {
        ret = implode(factors, ", ");
    }
    return configuration->decorate(sprintf("You are %-67s", ret), "content",
        "score", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator)
    {
        ret = 1;

        string colorConfiguration = initiator->colorConfiguration();
        int useUnicode = initiator->charsetConfiguration() == "unicode";

        string score = configuration->decorate(sprintf("%s%s %s\n",
            initiator->Pretitle() ? initiator->Pretitle() + " " : "",
            capitalize(initiator->RealName()),
            initiator->Title()), "character", "score", colorConfiguration);

        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "top", "General") + 
            Dictionary->banneredContent(colorConfiguration, useUnicode,
            raceDetails(initiator, colorConfiguration, useUnicode) +
            overallLevel(initiator, colorConfiguration, useUnicode));
        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "center", "Vitals") + initiator->vitals();
        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "center", "Attributes") +
            initiator->attributes();
        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "center", "Guilds") +
            initiator->guildsDetails();

        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "center", "Combat Information") +
            getCombatData(initiator, colorConfiguration, useUnicode);
        score += Dictionary->buildBanner(colorConfiguration, useUnicode, 
            "center", "Details") +
            Dictionary->banneredContent(colorConfiguration, useUnicode,
                getBiologicalDetails(initiator, colorConfiguration, useUnicode)) +
            Dictionary->banneredContent(colorConfiguration, useUnicode,
                configuration->decorate(sprintf("%-75s", "You can find out "
                    "more via the 'skills', 'traits', and 'research' "
                    "commands."), "content", "score", colorConfiguration));
        
        if (sizeof(regexp(({ command }), "-v")))
        {
            score += combatStatistics(initiator, colorConfiguration, useUnicode);
        }
        score += Dictionary->buildBanner(colorConfiguration, useUnicode, "bottom", "-");
        tell_object(initiator, score);
    }
    return ret;
}
