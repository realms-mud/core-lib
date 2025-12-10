//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(int level, string guild)
{
    int runningLevel = User.guildLevel(guild);
    while ((User.guildLevel(guild) < level) && User.memberOfGuild(guild))
    {
        User.addExperience(1000 * runningLevel);
        User.advanceLevel(guild);
        command("exit", User);
        runningLevel = User.guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AdvanceToLevel" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object(
        "/lib/modules/guilds/selectors/constructedResearchSelector.c");
    Selector.setType("Aeromancer Spell");
    Selector.setConstructedGrouping("/guilds/aeromancer/construct/root.c");
    Selector.InitializeSelector();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.colorConfiguration("none");
    User.addCommands();

    move_object(Selector, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrect()
{
    Selector.initiateSelector(User);
    ExpectEq("Aeromancer Spell - Construct Spell Main Menu:\n"
        "[1] - Create New Aeromancer Spell    [2] - Exit Construct Spell Menu      \n"
        "You must select a number from 1 to 2.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void ConstructionDisplayWithCreatedSpellsIsCorrect()
{
    mapping constructedElement = ([
        "alias": "weasel",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form",
                "description": "This is the form.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function",
                "description": "This is the function.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "This is the effect.",
                "unordered": 1
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Zappy Thing",
        constructedElement));
    ExpectTrue(User.setConstructedResearch("Weaselstrike",
        constructedElement));
    ExpectTrue(User.setConstructedResearch("Weasel Blast",
        constructedElement));
    ExpectTrue(User.setConstructedResearch("Weasels are the land-loving mother pigeon of creatures",
        constructedElement));

    constructedElement["constraint"] = "/lib/tests/support/research/flightOfWeasels.c";
    ExpectTrue(User.setConstructedResearch("This shouldn't appear in list",
        constructedElement));

    Selector.initiateSelector(User);
    ExpectEq("Aeromancer Spell - Construct Spell Main Menu:\n"
        "[1] - Modify 'Weasel Blast'          [2] - Modify 'Weasels are the l...'  \n"
        "[3] - Modify 'Weaselstrike'          [4] - Modify 'Zappy Thing'           \n"
        "[5] - Create New Aeromancer Spell    [6] - Exit Construct Spell Menu      \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeASpellShowsCorrectDetails()
{
    mapping constructedElement = ([
        "alias": "weasel",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form",
                "description": "This is the form."
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function",
                "description": "This is the function."
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "This is the effect."
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Flight of the Weasels",
        constructedElement));

    Selector.initiateSelector(User);
    command("? 1", User);

    ExpectEq("Aeromancer Spell Name : Flight of the Weasels\n"
        "Alias           : weasel\n"
        "Composition Elements : 3\n"
        "    * Arc Form\n"
        "      Form            : This is the form.\n"
        "      This research enhances 'Constructed Spell Multiplier' by +12%\n"
        "      Spell point cost of constructed items increased by 8.\n"
        "      Cooldown of constructed items increased by 4s.\n"
        "      \n"
        "    * Lightning Damage\n"
        "      Function        : This is the function.\n"
        "      This research enhances 'Constructed Spell Multiplier' by +125%\n"
        "      Constructed items cause electricity damage.\n"
        "      Spell point cost of constructed items increased by 75.\n"
        "      Cooldown of constructed items increased by 30s.\n"
        "      \n"
        "    * Damage Hit Points\n"
        "      Effect          : This is the effect.\n"
        "      Usage effect    : 80% chance to damage hit points 5 - 15\n"
        "      Usage effect    : 20% chance to damage hit points 10 - 30\n"
        "                        Modified -> +14% if Spell Focus is researched\n"
        "                        Modified -> +14% if Enhanced Focus is researched\n"
        "                        Modified -> +14% if Spell Amplification is researched\n"
        "                        Modified -> +14% if Spell Mastery is researched\n"
        "                        Modified -> +14% if Arcane Precision is researched\n"
        "                        Modified -> +20% if Spell Perfection is researched\n"
        "                        Modified -> 1.05 * your staff weapon damage (additive)\n"
        "                        Modified -> 1.25 * your not a staff weapon damage\n"
        "                                    (subtractive)\n"
        "                        Modified -> 0.10 * your elemental air skill (additive)\n"
        "                        Modified -> 1.05 * your level (logarithmic)\n"
        "                        Modified -> 1.25 * your spellcraft skill (logarithmic)\n"
        "                        Modified -> 1.25 * your magical essence skill\n"
        "                                    (logarithmic)\n"
        "                        Modified -> 0.10 * your physics skill (additive)\n"
        "                        Modified -> 0.05 * your mathematics skill (additive)\n"
        "                        Modified -> 0.05 * your chemistry skill (additive)\n"
        "                        Modified -> 0.05 * your intelligence attribute\n"
        "                                    (additive)\n"
        "                        Modified -> 0.03 * your dexterity attribute (additive)\n"
        "                        Modified -> 0.03 * your wisdom attribute (additive)\n"
        "      \n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSpellWithMultipleEffectsShowsCorrectDetails()
{
    mapping constructedElement = ([
        "alias": "tempest",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/cyclone.c",
                "type": "form",
                "description": "A swirling cyclone of air."
            ]),
            ([ "research": "/guilds/aeromancer/functions/wind.c",
                "type": "function",
                "description": "Powered by fierce winds."
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "Deals damage to targets."
            ]),
            ([ "research": "/guilds/aeromancer/effects/reduce-attack.c",
                "type": "effect",
                "description": "Reduces enemy attack capability."
            ]),
            ([ "research": "/guilds/aeromancer/effects/apply-slow.c",
                "type": "effect",
                "description": "Slows enemy movement."
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Tempest Strike",
        constructedElement));

    Selector.initiateSelector(User);
    command("? 1", User);

    // Verify the spell was created with 5 elements
    ExpectSubStringMatch("Aeromancer Spell Name : Tempest Strike", 
        User.caughtMessage());
    ExpectSubStringMatch("Alias           : tempest", 
        User.caughtMessage());
    ExpectSubStringMatch("Composition Elements : 5", 
        User.caughtMessage());

    // Verify form component
    ExpectSubStringMatch("Cyclone Form", User.caughtMessage());
    ExpectSubStringMatch("Form            : A swirling cyclone of air.", 
        User.caughtMessage());

    // Verify function component
    ExpectSubStringMatch("Wind Damage", User.caughtMessage());
    ExpectSubStringMatch("Function        : Powered by fierce winds.", 
        User.caughtMessage());

    // Verify all three effect components are present
    ExpectSubStringMatch("Damage Hit Points", User.caughtMessage());
    ExpectSubStringMatch("Effect          : Deals damage to targets.", 
        User.caughtMessage());

    ExpectSubStringMatch("Reduce Attack", User.caughtMessage());
    ExpectSubStringMatch("Effect          : Reduces enemy attack capability.", 
        User.caughtMessage());

    ExpectSubStringMatch("Apply Slow", User.caughtMessage());
    ExpectSubStringMatch("Effect          : Slows enemy movement.", 
        User.caughtMessage());

    // Verify modifiers are shown for effects
    ExpectSubStringMatch("Modified -> \\+14% if Spell Focus is researched", 
        User.caughtMessage());
    ExpectSubStringMatch("Modified -> \\+20% if Spell Perfection is researched", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitClosesSelector()
{
    Selector.initiateSelector(User);
    command("2", User);

    ExpectSubStringMatch("You have selected", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TypingExitClosesSelector()
{
    Selector.initiateSelector(User);
    command("exit", User);

    ExpectSubStringMatch("has been exited", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingModifyOpensEditSelector()
{
    mapping constructedElement = ([
        "alias": "zap",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function"
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect"
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Zap Spell",
        constructedElement));

    Selector.initiateSelector(User);
    command("1", User);

    // Should show the edit menu with spell details
    ExpectSubStringMatch("Modify Spell Menu", User.caughtMessage());
    ExpectSubStringMatch("Spell Name: Zap Spell", User.caughtMessage());
    ExpectSubStringMatch("Spell Alias: zap", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingCreateOpensCreateSelector()
{
    Selector.initiateSelector(User);
    command("1", User);

    // Should show the create menu
    ExpectSubStringMatch("Create New Constructed Spell", User.caughtMessage());
    ExpectSubStringMatch("Create Constructed Aeromancer Spells", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DeleteSpellRemovesItFromList()
{
    mapping constructedElement = ([
        "alias": "delete-me",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function"
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect"
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Delete Me Spell",
        constructedElement));

    // Verify spell exists
    mapping spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectTrue(member(spells, "Delete Me Spell"));

    // Delete it
    ExpectTrue(User.deleteConstructedResearch("Delete Me Spell"));

    // Verify spell is gone
    spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectFalse(member(spells, "Delete Me Spell"));
}

/////////////////////////////////////////////////////////////////////////////
void SetConstructedResearchValidatesData()
{
    // Missing constraint
    mapping invalidElement = ([
        "alias": "test",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]);
    ExpectFalse(User.setConstructedResearch("Invalid Spell", invalidElement));

    // Missing type
    invalidElement = ([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]);
    ExpectFalse(User.setConstructedResearch("Invalid Spell", invalidElement));

    // Valid with empty elements
    mapping validElement = ([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]);
    ExpectTrue(User.setConstructedResearch("Valid Spell", validElement));
}

/////////////////////////////////////////////////////////////////////////////
void GetOptionsForConstructedResearchFiltersbyConstraint()
{
    // Create two spells with the same valid type but pretend they have 
    // different constraints by creating them directly in the mapping.
    // The selector filters based on the constraint field.
    
    mapping spell1 = ([
        "alias": "spell1",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]);

    ExpectTrue(User.setConstructedResearch("Aeromancer Spell", spell1));

    // Only aeromancer spells should appear when filtering by aeromancer constraint
    mapping spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectEq(1, member(spells, "Aeromancer Spell"), 
        "Aeromancer Spell exists in aeromancer constraint");

    // No spells should appear with a different constraint
    spells = User.getOptionsForConstructedResearch(
        "/guilds/scion/construct/root.c");
    ExpectEq(0, sizeof(spells),
        "No spells returned for different constraint");
}

/////////////////////////////////////////////////////////////////////////////
void GetConstructedResearchByAliasWorks()
{
    mapping spell = ([
        "alias": "zappy",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Zappy Spell", spell));

    // Retrieve by name
    mapping result = User.getConstructedResearch(
        "/guilds/aeromancer/construct/root.c", "Zappy Spell");
    ExpectEq("zappy", result["alias"]);

    // Retrieve by alias
    result = User.getConstructedResearch(
        "/guilds/aeromancer/construct/root.c", "zappy");
    ExpectEq("zappy", result["alias"]);
}

/////////////////////////////////////////////////////////////////////////////
void SpellMissingComponentsCannotBeSaved()
{
    // Create a spell with only a form - missing function and effect
    mapping spell = ([
        "name": "Incomplete Spell",
        "alias": "incomplete",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Incomplete Spell", spell));

    Selector.initiateSelector(User);
    command("1", User);  // Modify the spell

    // The save option should be disabled because function and effect are missing
    ExpectSubStringMatch("Save the spell.*\\(X\\)", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpellWithAllRequiredComponentsCanBeSaved()
{
    mapping spell = ([
        "name": "Complete Spell",
        "alias": "complete",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function"
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect"
            ]),
        })
    ]);

    ExpectTrue(User.setConstructedResearch("Complete Spell", spell));

    Selector.initiateSelector(User);
    command("1", User);  // Modify the spell

    // The save option should NOT be disabled (no (X) marker)
    ExpectSubStringMatch("Save the spell", User.caughtMessage());
    // Make sure it's not disabled
    string message = User.caughtMessage();
    int savePos = strstr(message, "Save the spell");
    int disabledPos = strstr(message, "(X)", savePos);
    int nextOptionPos = strstr(message, "Delete the spell", savePos);
    
    // (X) should either not appear or appear after the next option
    ExpectTrue(disabledPos == -1 || disabledPos > nextOptionPos);
}

/////////////////////////////////////////////////////////////////////////////
void DescribeCreateNewShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 1", User);

    ExpectSubStringMatch("This option allows you to create a custom Aeromancer Spell",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeExitShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 2", User);

    ExpectSubStringMatch("This option leaves the construct Aeromancer Spell menu",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpellsAreSortedAlphabetically()
{
    mapping baseSpell = ([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form"
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function"
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect"
            ]),
        })
    ]);

    // Create spells in non-alphabetical order
    ExpectTrue(User.setConstructedResearch("Zebra Spell", baseSpell));
    ExpectTrue(User.setConstructedResearch("Alpha Spell", baseSpell));
    ExpectTrue(User.setConstructedResearch("Middle Spell", baseSpell));

    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    int zebraPos = strstr(message, "Zebra");
    int middlePos = strstr(message, "Middle");
    int alphaPos = strstr(message, "Alpha");
    
    // Make sure all spells were found
    ExpectTrue(zebraPos >= 0, "Zebra Spell found in message");
    ExpectTrue(middlePos >= 0, "Middle Spell found in message");
    ExpectTrue(alphaPos >= 0, "Alpha Spell found in message");
    
    ExpectTrue(zebraPos > middlePos, "Zebra appears after Middle");
    ExpectTrue(middlePos > alphaPos, "Middle appears after Alpha");
}
