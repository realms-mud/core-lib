//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private object Dictionary = 
    load_object("/lib/dictionaries/commandsDictionary.c");

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("stat ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string overallLevel(object target,
    string colorConfiguration)
{
    string level = target->isRealizationOf("wizard") ?
        capitalize(target->wizardLevel()) :
        to_string(target->effectiveLevel());

    return configuration->decorate("Overall Level: ", "content", "score",
        colorConfiguration) +
        configuration->decorate(sprintf("%-21s", level), "value", "score",
            colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string raceDetails(object target,
    string colorConfiguration)
{
    object raceDictionary = load_object("/lib/dictionaries/racialDictionary.c");
    return configuration->decorate("Race: ", "content", "score",
        colorConfiguration) +
        configuration->decorate(sprintf("%-33s",
            raceDictionary->raceDetails(target)), "value", "score",
            colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string combatStatistics(object target,
    string colorConfiguration, string charset)
{
    mapping bestKill = target->getBestKill();
    string bestKillLine;
    if (sizeof(bestKill))
    {
        bestKillLine = configuration->decorate("Best Kill: ", "content", "score",
            colorConfiguration) +
            configuration->decorate(bestKill["name"] + " ", "information", "score",
                colorConfiguration) +
            configuration->decorate(sprintf("(Level %s) ", bestKill["level"]),
                "statistics level", "score", colorConfiguration) +
            configuration->decorate(sprintf("was killed %s times.",
                bestKill["times killed"]), "statistics info", "score",
                colorConfiguration);
    }
    else
    {
        bestKillLine = configuration->decorate("Best Kill: ", "content", "score",
            colorConfiguration) +
            configuration->decorate("<nobody>", "information", "score",
                colorConfiguration);
    }

    mapping nemesis = target->getNemesis();
    string nemesisLine;
    if (sizeof(nemesis))
    {
        nemesisLine = configuration->decorate("Nemesis: ", "content", "score",
            colorConfiguration) +
            configuration->decorate(nemesis["name"] + " ", "information", "score",
                colorConfiguration) +
            configuration->decorate(sprintf("(Level %s) ", nemesis["level"]),
                "statistics level", "score", colorConfiguration) +
            configuration->decorate(sprintf("was killed %s times.",
                nemesis["times killed"]), "statistics info", "score",
                colorConfiguration);
    }
    else
    {
        nemesisLine = configuration->decorate("Nemesis: ", "content", "score",
            colorConfiguration) +
            configuration->decorate("<nobody>", "information", "score",
                colorConfiguration);
    }

    return Dictionary->buildBanner(colorConfiguration, charset, "center",
        "Combat Statistics") +
        Dictionary->banneredContent(colorConfiguration, charset, bestKillLine) +
        Dictionary->banneredContent(colorConfiguration, charset, nemesisLine);
}


/////////////////////////////////////////////////////////////////////////////
private nomask string getWeaponData(object target, object weapon,
    int isPrimary, string colorConfiguration, string charset)
{
    string location = isPrimary ? "Primary" : "Offhand";

    string name = weapon->query("short");
    if (sizeof(name) > 15)
    {
        name = name[0..11] + "...";
    }
    int attack = target->calculateAttack(0, weapon, 1);
    int damage = target->calculateDamage(weapon, "physical", 1);
    if (!damage)
    {
        damage = 1;
    }

    return Dictionary->banneredContent(colorConfiguration, charset,
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
private nomask string getDefensiveStats(object target,
    string colorConfiguration, string charset)
{
    int defend = target->calculateDefendAttack();
    int soak = target->calculateSoakDamage("physical");

    return Dictionary->banneredContent(colorConfiguration, charset,
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
            target->inventoryGetEncumberance(), ""),
            "weapon", "score", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCombatData(object target,
    string colorConfiguration, string charset)
{
    string ret = "";

    object materialsDictionary =
        load_object("/lib/dictionaries/materialsDictionary.c");

    object nullEquipment =
        load_object("/lib/items/equipment.c");

    object primaryWeapon = target->equipmentInSlot("wielded primary");
    if (!primaryWeapon)
    {
        primaryWeapon = nullEquipment;
    }
    object offhandWeapon = target->equipmentInSlot("wielded offhand");

    ret += getWeaponData(target, primaryWeapon, 1, colorConfiguration,
        charset);

    if (offhandWeapon)
    {
        ret += getWeaponData(target, offhandWeapon, 0, colorConfiguration,
            charset);
    }

    ret += getDefensiveStats(target, colorConfiguration, charset);

    string hostiles = target->getHostileList();
    if (sizeof(hostiles) > 35)
    {
        hostiles = hostiles[0..31] + "...";
    }
    ret += Dictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate(sprintf("%14s: ", "Wimpy"),
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%3d%%",
            target->Wimpy(0, 1)),
            "weapon", "score", colorConfiguration) +
        configuration->decorate(sprintf("%18s: ", "Hunted by"),
            "content", "score", colorConfiguration) +
        configuration->decorate(sprintf("%-35s", hostiles),
            "weapon", "score", colorConfiguration));

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private object getObjectToDisplay(string name, object initiator)
{
    object *targets = filter(users(), (: $1->RealName() == $2 :), name);
    object target = 0;

    if (sizeof(targets))
    {
        target = targets[0];
    }
    else
    {
        target = present(name, environment(initiator)) ||
            present(name, initiator);
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private string getLivingDetails(object target,
    string colorConfiguration, string charset)
{
    string ret = configuration->decorate(sprintf("%s%s %s\n",
        target->Pretitle() ? target->Pretitle() + " " : "",
        capitalize(target->RealName()),
        target->Title()), "character", "score", colorConfiguration);

    ret += Dictionary->buildBanner(colorConfiguration, charset,
        "top", "General") +
        Dictionary->banneredContent(colorConfiguration, charset,
            raceDetails(target, colorConfiguration) +
            overallLevel(target, colorConfiguration));
    ret += Dictionary->buildBanner(colorConfiguration, charset,
        "center", "Vitals") + target->vitals(colorConfiguration, charset);
    ret += Dictionary->buildBanner(colorConfiguration, charset,
        "center", "Attributes") +
        target->attributes(colorConfiguration, charset);

    string guildDetails =
        target->guildsDetails(colorConfiguration, charset);
    if (guildDetails)
    {
        ret += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Guilds") + guildDetails;
    }
    else if (target->persona())
    {
        ret += Dictionary->buildBanner(colorConfiguration, charset,
                "center", "Persona Details") + 
            Dictionary->banneredContent(colorConfiguration, charset,
                configuration->decorate(sprintf("%-75s",
                    sprintf("This character has "
                    "the '%s' persona.", target->persona())),
                    "content", "score", colorConfiguration));
    }

    ret += Dictionary->buildBanner(colorConfiguration, charset,
        "center", "Combat Information") +
        getCombatData(target, colorConfiguration, charset);

    if (target->isRealizationOfPlayer())
    {
        ret +=
            Dictionary->buildBanner(colorConfiguration, charset,
                "center", "Other Information") +
            Dictionary->banneredContent(colorConfiguration, charset,
                configuration->decorate("IP: ",
                    "content", "score", colorConfiguration) +
                configuration->decorate(
                    sprintf("%-18s", query_ip_name(target) || "???"),
                    "weapon", "score", colorConfiguration) +
                configuration->decorate("Age: ",
                    "content", "score", colorConfiguration) +
                configuration->decorate(sprintf("%-48s", target->ageString()),
                    "weapon", "score", colorConfiguration));
    }
    else
    {
        ret +=
            Dictionary->buildBanner(colorConfiguration, charset,
                "center", "Other Information") +
            Dictionary->banneredContent(colorConfiguration, charset,
                configuration->decorate("Filename: ",
                    "content", "score", colorConfiguration) +
                configuration->decorate(sprintf("%-65s",
                    program_name(target)),
                    "weapon", "score", colorConfiguration));
    }

    ret += Dictionary->buildBanner(colorConfiguration, charset, "bottom",
        (charset != "screen reader" ? "-" : ""));

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("stat"))
    {
        string targetString = getTargetString(initiator, command);

        object target = 0;
        if (!targetString || (targetString == ""))
        {
            target = environment(initiator);
        }
        else
        {
            target = getObjectToDisplay(targetString, initiator);
        }

        if (target)
        {
            ret = 1;
            string colorConfiguration = initiator->colorConfiguration();
            string charset = initiator->charsetConfiguration();

            string score = "";

            if (target->isRealizationOfLiving())
            {
                score = getLivingDetails(target, colorConfiguration, charset);
            }
            else if (member(inherit_list(target), "/lib/items/item.c") > -1)
            {
                score = Dictionary->buildBanner(colorConfiguration, charset,
                        "center", "File Information") +
                    Dictionary->banneredContent(colorConfiguration, charset,
                        configuration->decorate("Filename: ",
                            "content", "score", colorConfiguration) +
                        configuration->decorate(sprintf("%-65s",
                            program_name(target)),
                            "weapon", "score", colorConfiguration));

                score += Dictionary->buildBanner(colorConfiguration, charset,
                        "center", "Detailed Information") +
                    target->long(1);
            }
            tell_object(initiator, score);

        }
        else
        {
            notify_fail(sprintf("Could not find '%s'.\n", targetString));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display game statistics for the target.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The stat command will display basic game-affecting "
        "information about the specified living or item object - "
        "specifically around its attributes and modifiers related to "
        "comabt.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: show";
}
