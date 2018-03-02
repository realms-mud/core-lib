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
        CommandType = "player information";
        addCommandTemplate("score");
        addCommandTemplate("?");

        Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string overallLevel(object initiator)
{
    string format = " [0;36mOverall Level:[0m [0;32m%-22s[0m[0;31m|[0m\n";

    string level = initiator->isRealizationOf("wizard") ?
        capitalize(initiator->wizardLevel()) :
        to_string(initiator->effectiveLevel());

    return sprintf(format, level);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string raceDetails(object initiator)
{
    object raceDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    return sprintf("[0;31m|[0m [0;36mRace:[0m [0;32m%-32s[0m",
        raceDictionary->raceDetails(initiator));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getWeaponData(object initiator, object weapon, int isPrimary)
{
    string format = "[0;36m%s: [0m[0;33m%d to %d[0m";
    string row = "[0;31m|[0m [0;36m%7s Weapon:[0m [0;33m%-15s[0m %-46s %-40s [0;31m|[0m\n";

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

    return sprintf(row, location,
        weapon->query("short") ? name : "No Weapon",
        sprintf(format, "Attack", attack - 25, attack + 75),
        sprintf(format, "Damage", to_int(damage * 7.0 / 8.0),
            to_int(damage * 9.0 / 8.0)));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDefensiveStats(object initiator)
{
    string format = "[0;36m%s: [0m[0;33m%d to %d[0m";
    string row = "[0;31m|[0m  %-54s %-38s %-46s [0;31m|[0m\n";

    int defend = initiator->calculateDefendAttack();
    int soak = initiator->calculateSoakDamage("physical");

    return sprintf(row, sprintf(format, "Defend Attack",
        defend - abs(defend / 2), defend),
        sprintf(format, "Soak", soak - abs(soak / 2), soak),
        sprintf("[0;36m%s: [0m[0;33m%d[0m", "Encumberance",
            initiator->inventoryGetEncumberance()));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCombatData(object initiator)
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

    ret += getWeaponData(initiator, primaryWeapon, 1);
    if (offhandWeapon)
    {
        ret += getWeaponData(initiator, offhandWeapon, 0);
    }

    ret += getDefensiveStats(initiator);

    string hostiles = initiator->getHostileList();
    if (sizeof(hostiles) > 35)
    {
        hostiles = hostiles[0..31] + "...";
    }
    ret += sprintf("[0;31m|[0m [0;36m%14s: [0m[0;33m%d%% [0m[0;36m%19s: [0m[0;33m%-35s[0m [0;31m|[0m\n",
        "Wimpy", initiator->Wimpy(0, 1), "Hunted by", hostiles);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getBiologicalDetails(object initiator)
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
    return "You are " + ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;

        string score = sprintf("[0;32m%s%s %s[0m\n",
            initiator->Pretitle() ? initiator->Pretitle() + " " : "",
            capitalize(initiator->RealName()),
            initiator->Title());
        score += Dictionary->buildBanner("General") +
            raceDetails(initiator) + overallLevel(initiator);
        score += Dictionary->buildBanner("Vitals") + initiator->vitals();
        score += Dictionary->buildBanner("Attributes") +
            initiator->attributes();
        score += Dictionary->buildBanner("Guilds") +
            initiator->guildsDetails();

        score += Dictionary->buildBanner("Combat Information") +
            getCombatData(initiator);
        score += Dictionary->buildBanner("Details") +
            sprintf("[0;31m|[0m [0;36m%-75s[0m [0;31m|[0m\n",
                getBiologicalDetails(initiator)) +
            sprintf("[0;31m|[0m [0;36m%-75s[0m [0;31m|[0m\n",
                "You can find out more via the 'skills', 'traits', and 'research' commands.") +
            Dictionary->buildBanner("-");
        tell_object(initiator, score);
    }
    return ret;
}
