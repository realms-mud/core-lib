//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Information";
    addCommandTemplate("score [-v]");
    addCommandTemplate("? [-v]"); 

    Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string overallLevel(object initiator,
    string colorConfiguration)
{
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
    string colorConfiguration)
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
    string colorConfiguration, string charset)
{
    mapping bestKill = initiator->getBestKill();
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

    mapping nemesis = initiator->getNemesis();
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
private nomask string getWeaponData(object initiator, object weapon, 
    int isPrimary, string colorConfiguration, string charset)
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
private nomask string getDefensiveStats(object initiator,
    string colorConfiguration, string charset)
{
    int defend = initiator->calculateDefendAttack();
    int soak = initiator->calculateSoakDamage("physical");

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
            initiator->inventoryGetEncumberance(), ""),
            "weapon", "score", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCombatData(object initiator,
    string colorConfiguration, string charset)
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
        charset);

    if (offhandWeapon)
    {
        ret += getWeaponData(initiator, offhandWeapon, 0, colorConfiguration, 
            charset);
    }

    ret += getDefensiveStats(initiator, colorConfiguration, charset);

    string hostiles = initiator->getHostileList();
    if (sizeof(hostiles) > 35)
    {
        hostiles = hostiles[0..31] + "...";
    }
    ret += Dictionary->banneredContent(colorConfiguration, charset,
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
    string colorConfiguration)
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
        string charset = initiator->charsetConfiguration();

        string score = configuration->decorate(sprintf("%s%s %s\n",
            initiator->Pretitle() ? initiator->Pretitle() + " " : "",
            capitalize(initiator->RealName()),
            initiator->Title()), "character", "score", colorConfiguration);

        score += Dictionary->buildBanner(colorConfiguration, charset,
            "top", "General") + 
            Dictionary->banneredContent(colorConfiguration, charset,
            raceDetails(initiator, colorConfiguration) +
            overallLevel(initiator, colorConfiguration));
        score += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Vitals") + initiator->vitals();
        score += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Attributes") +
            initiator->attributes();
        score += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Guilds") +
            initiator->guildsDetails();

        score += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Combat Information") +
            getCombatData(initiator, colorConfiguration, charset);
        score += Dictionary->buildBanner(colorConfiguration, charset,
            "center", "Details") +
            Dictionary->banneredContent(colorConfiguration, charset,
                getBiologicalDetails(initiator, colorConfiguration)) +
            Dictionary->banneredContent(colorConfiguration, charset,
                configuration->decorate(sprintf("%-75s", "You can find out "
                    "more via the 'skills', 'traits', and 'research' "
                    "commands."), "content", "score", colorConfiguration));
        
        if (sizeof(regexp(({ command }), "-v")))
        {
            score += combatStatistics(initiator, colorConfiguration, charset);
        }
        score += Dictionary->buildBanner(colorConfiguration, charset, "bottom", 
            (charset != "screen reader" ? "-" : ""));
        tell_object(initiator, score);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Displays the player's general information page";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    
    switch (parsedFlag)
    {
        case "-v":
        {
            ret = "This option will display verbose information about "
                "the player such as best kill and other combat statistics.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Score will display the character's vitals, race, attributes, "
        "and high-level combat information. In verbose mode, it will also "
        "display combat statistics for the character.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: inventory, quests, research, traits, and vitals";
}
