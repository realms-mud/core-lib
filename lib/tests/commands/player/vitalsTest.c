//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("rob");
    Player.hitPoints(30);
    Player.spellPoints(30);
    Player.staminaPoints(30);
    Player.Str(10);
    Player.Int(10);
    Player.Dex(10);
    Player.Wis(10);
    Player.Con(10);
    Player.Chr(10);
    Player.addCommands();
    Player.Race("high elf");
    Player.addTrait("/lib/instances/traits/racial/hillgarathElf.c");
    Player.addTrait("/lib/instances/traits/genetic/smart.c");
    Player.spellPoints(Player.maxSpellPoints());
    Player.staminaPoints(Player.maxStaminaPoints());

    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild.create();
    Player.joinGuild("fake mage");
    Player.addExperience(1700);
    Player.advanceLevel("fake mage");

    guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    guild.create();
    Player.joinGuild("fake fighter");
    Player.addExperience(2000);

    move_object(Player, load_object("/lib/tests/support/environment/fakeEnvironment.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteVitalsCommand()
{
    ExpectTrue(Player.executeCommand("vitals"));
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("vitals"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Hit Points:.*[^=]==[^=]")), "shows two bars");
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "30/121")), "shows 30/121");

    Player.hitPoints(32);
    ExpectTrue(Player.executeCommand("vitals"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Hit Points:.*[^=]=====[^=]")), "shows 5 bars");
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "62/121")), "shows 62/121");
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("vitals"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Spell Points:.*[^=]==========[^=]")));
    Player.spellPoints(-30);
    ExpectTrue(Player.executeCommand("vitals"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Spell Points:.*[^=]========[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("vitals"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Stamina:.*[^=]==========[^=]")));
    Player.staminaPoints(-30);
    ExpectTrue(Player.executeCommand("vitals"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Stamina:.*[^=]======[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void HelpForVitalsDisplaysProperInfo()
{
    Player.pageSize(200);
    ExpectTrue(Player.executeCommand("help vitals"));
    ExpectEq("\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Help for Vitals +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;36;1mSynopsis\n"
        "\x1b[0m\x1b[0;36m\tvitals - Display a character's vitals\n"
        "\x1b[0m\x1b[0;36;1m\nSyntax\n"
        "\x1b[0m\t\x1b[0;36mvitals\n"
        "\t\t\x1b[0m\n"
        "[0;36;1mDescription\n"
        "\x1b[0m\x1b[0;36mThe vitals command displays information about your current hit points, spell\n"
        "points, and stamina points levels.\n"
        "\n"
        "For example:\n"
        "> vitals\n"
        "\x1b[0;36mHit Points: \x1b[0m\x1b[0;35;1m==\x1b[0m\x1b[0;31m........\x1b[0m\x1b[0;36m   "
        "Spell Points: \x1b[0m\x1b[0;35;1m========\x1b[0m\x1b[0;31m..\x1b[0m\x1b[0;36m       "
        "Stamina: \x1b[0m\x1b[0;35;1m========== \x1b[0m\x1b[0;33m                "
        "30 / 121                    122 / 152                 96 / 96  \x1b[0m\x1b[0m\x1b[0;36;1m\n"
        "Options\n"
        "\x1b[0m\x1b[0;36m\tThis command does not have any options.\n\x1b[0m\n"
        "\x1b[0;36;1mNotes\n"
        "\t\x1b[0m\x1b[0;36mSee also: score\x1b[0m"
        "\x1b[0;36;1m\n\nCopyright\n"
        "\x1b[0m\x1b[0;36m\tCopyright (C) 1991-2024 Allen Cummings. For additional licensing\n"
        "\tinformation, see \x1b[0m\x1b[0;36mhttp://realmsmud.org/license/\n\x1b[0m",
        Player.caughtMessage());
}
