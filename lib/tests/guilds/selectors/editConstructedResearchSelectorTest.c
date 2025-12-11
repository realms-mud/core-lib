//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object(
        "/lib/modules/guilds/selectors/editConstructedResearchSelector.c");
    Selector.setType("modify");
    Selector.setConstraint("/guilds/aeromancer/construct/root.c");
    Selector.setData(([
        "name": "Test Spell",
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
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
void InitializeSelectorSetsCorrectDefaults()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // Verify menu displays correctly
    ExpectSubStringMatch("Modify Spell Menu", message);
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
    ExpectSubStringMatch("For details on a given choice", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsSpellDetails()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    ExpectSubStringMatch("Spell Type:", message);
    ExpectSubStringMatch("Spell Name: Test Spell", message);
    ExpectSubStringMatch("Spell Alias: test", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsMissingNameWhenNoName()
{
    Selector.setData(([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Spell Name: <Name Missing>", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsNoAliasWhenNoAlias()
{
    Selector.setData(([
        "name": "Test Spell",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Spell Alias: <No Alias>", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsAddComponentOptions()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    ExpectSubStringMatch("Add Effect component", message);
    ExpectSubStringMatch("Add Form component", message);
    ExpectSubStringMatch("Add Function component", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsNameAndAliasOptions()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    ExpectSubStringMatch("Set/change spell name", message);
    ExpectSubStringMatch("Set/change spell alias", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsSaveAndDeleteOptions()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    ExpectSubStringMatch("Save the spell", message);
    ExpectSubStringMatch("Delete the spell", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsExitOption()
{
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Exit Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SaveIsDisabledWhenMissingRequiredComponents()
{
    // Spell with no components
    Selector.setData(([
        "name": "Test Spell",
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    int savePos = strstr(message, "Save the spell");
    int disabledPos = strstr(message, "(X)", savePos);
    int deletePos = strstr(message, "Delete the spell");
    
    ExpectTrue(disabledPos != -1 && disabledPos < deletePos,
        "Save option should be disabled when missing components");
}

/////////////////////////////////////////////////////////////////////////////
void SaveIsEnabledWhenAllRequiredComponentsPresent()
{
    // Add all required research
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/forms/arc.c");
    User.initiateResearch("/guilds/aeromancer/functions/lightning.c");
    User.initiateResearch("/guilds/aeromancer/effects/damage-hp.c");

    Selector.setData(([
        "name": "Test Spell",
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form" ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function" ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect" ])
        })
    ]));
    
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    int savePos = strstr(message, "Save the spell");
    int nextLinePos = strstr(message, "\n", savePos);
    string saveLine = message[savePos..nextLinePos];
    
    ExpectFalse(strstr(saveLine, "(X)") != -1,
        "Save option should be enabled when all components present");
}

/////////////////////////////////////////////////////////////////////////////
void DeleteIsDisabledWhenNoName()
{
    Selector.setData(([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    int deletePos = strstr(message, "Delete the spell");
    int disabledPos = strstr(message, "(X)", deletePos);
    int exitPos = strstr(message, "Exit Menu");
    
    ExpectTrue(disabledPos != -1 && disabledPos < exitPos,
        "Delete option should be disabled when no name");
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSetNamePromptsForInput()
{
    Selector.initiateSelector(User);
    command("4", User);  // Set/change spell name
    
    ExpectSubStringMatch("Please enter the spell's new name:", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EnteringNameUpdatesSpellData()
{
    Selector.initiateSelector(User);
    command("4", User);  // Set/change spell name
    command("My New Spell", User);
    
    ExpectSubStringMatch("Spell Name: My New Spell", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSetAliasPromptsForInput()
{
    Selector.initiateSelector(User);
    command("5", User);  // Set/change spell alias
    
    ExpectSubStringMatch("Please enter the spell's new alias:", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EnteringAliasUpdatesSpellData()
{
    Selector.initiateSelector(User);
    command("5", User);  // Set/change spell alias
    command("myalias", User);
    
    ExpectSubStringMatch("Spell Alias: myalias", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingDeletePromptsForConfirmation()
{
    Selector.initiateSelector(User);
    command("7", User);  // Delete the spell
    
    ExpectSubStringMatch("Are you sure you want to delete this spell", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConfirmingDeleteRemovesSpell()
{
    // First save the spell
    User.setConstructedResearch("Test Spell", ([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    command("7", User);  // Delete the spell
    command("yes", User);
    
    // Verify spell was deleted
    mapping spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectFalse(member(spells, "Test Spell"));
}

/////////////////////////////////////////////////////////////////////////////
void CancellingDeleteKeepsSpell()
{
    // First save the spell
    User.setConstructedResearch("Test Spell", ([
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    command("7", User);  // Delete the spell
    command("no", User);
    
    ExpectSubStringMatch("Deletion aborted", implode(User.caughtMessages(), "\n"));
    
    // Verify spell still exists
    mapping spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectTrue(member(spells, "Test Spell"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectingAddComponentOpensComponentSelector()
{
    Selector.initiateSelector(User);
    command("1", User);  // Add Effect component
    
    ExpectSubStringMatch("Select Effect Component", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitClosesSelector()
{
    Selector.initiateSelector(User);
    command("8", User);  // Exit Menu
    
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
void SavingSpellWithAllComponentsSucceeds()
{
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/forms/arc.c");
    User.initiateResearch("/guilds/aeromancer/functions/lightning.c");
    User.initiateResearch("/guilds/aeromancer/effects/damage-hp.c");

    Selector.setData(([
        "name": "Complete Spell",
        "alias": "complete",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form" ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function" ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect" ])
        })
    ]));
    
    Selector.initiateSelector(User);
    command("7", User);  // Save the spell (shifted due to component options)
    
    ExpectSubStringMatch("Spell saved", 
        implode(User.caughtMessages(), "\n"));
    
    // Verify spell was saved
    mapping spells = User.getOptionsForConstructedResearch(
        "/guilds/aeromancer/construct/root.c");
    ExpectTrue(member(spells, "Complete Spell"));
}

/////////////////////////////////////////////////////////////////////////////
void SavingSpellWithoutAliasUsesNameAsAlias()
{
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/forms/arc.c");
    User.initiateResearch("/guilds/aeromancer/functions/lightning.c");
    User.initiateResearch("/guilds/aeromancer/effects/damage-hp.c");

    Selector.setData(([
        "name": "No Alias Spell",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form" ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function" ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect" ])
        })
    ]));
    
    Selector.initiateSelector(User);
    command("7", User);  // Save the spell (shifted due to component options)
    
    // Verify spell was saved with name as alias
    mapping result = User.getConstructedResearch(
        "/guilds/aeromancer/construct/root.c", "No Alias Spell");
    ExpectEq("No Alias Spell", result["alias"]);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsSelectedComponentsWhenPresent()
{
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/forms/arc.c");

    Selector.setData(([
        "name": "Test Spell",
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form" ])
        })
    ]));
    
    Selector.initiateSelector(User);
    
    // Should show the selected form component
    ExpectSubStringMatch("\\[Form\\].*\\(selected\\)", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSelectedComponentRemovesIt()
{
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/forms/arc.c");

    Selector.setData(([
        "name": "Test Spell",
        "alias": "test",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form" ])
        })
    ]));
    
    Selector.initiateSelector(User);
    
    // Find which option is the selected form component
    string message = User.caughtMessage();
    
    // The selected form should appear as "[Form] Arc Form (selected)"
    // Need to find the option number for it
    ExpectSubStringMatch("\\[Form\\] Arc Form \\(selected\\)", message);
    
    // Option 1 is "Add Effect component", option 2 is the selected form
    command("2", User);
    
    // After removal, should no longer show the selected form
    message = User.caughtMessage();
    ExpectFalse(strstr(message, "[Form] Arc Form (selected)") != -1,
        "Selected form should be removed");
    ExpectSubStringMatch("Add Form component", message);
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSetNameShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 4", User);
    
    ExpectSubStringMatch("Set or change the name of the spell", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSetAliasShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 5", User);
    
    ExpectSubStringMatch("Set or change the alias of the spell", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSaveShowsCorrectDetailsWhenDisabled()
{
    Selector.initiateSelector(User);
    command("? 6", User);
    
    ExpectSubStringMatch("Cannot save: spell requires a name, form, function", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDeleteShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 7", User);
    
    ExpectSubStringMatch("This option deletes the spell", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeExitShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 8", User);
    
    ExpectSubStringMatch("This option leaves the spell composition menu", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CreateTypeSetsMenuTitleToCreate()
{
    Selector.setType("create");
    Selector.setData(([
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({})
    ]));
    
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Create Spell Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ModifyTypeSetsMenuTitleToModify()
{
    Selector.setType("modify");
    
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Modify Spell Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SuppressMenuDisplayWhenSettingName()
{
    Selector.initiateSelector(User);
    command("4", User);  // Set name - puts selector in SettingName mode
    
    // Menu should be suppressed, only showing the prompt
    string message = User.caughtMessage();
    ExpectSubStringMatch("Please enter the spell's new name:", message);
    
    // Should NOT show the full menu while in input mode
    ExpectFalse(strstr(message, "Exit Menu") != -1);
}

/////////////////////////////////////////////////////////////////////////////
void SuppressMenuDisplayWhenSettingAlias()
{
    Selector.initiateSelector(User);
    command("5", User);  // Set alias - puts selector in SettingAlias mode
    
    // Menu should be suppressed, only showing the prompt
    string message = User.caughtMessage();
    ExpectSubStringMatch("Please enter the spell's new alias:", message);
    
    // Should NOT show the full menu while in input mode
    ExpectFalse(strstr(message, "Exit Menu") != -1);
}

/////////////////////////////////////////////////////////////////////////////
void SuppressMenuDisplayWhenConfirmingDelete()
{
    Selector.initiateSelector(User);
    command("7", User);  // Delete - puts selector in DeletingSpell mode
    
    // Menu should be suppressed, only showing the prompt
    string message = User.caughtMessage();
    ExpectSubStringMatch("Are you sure you want to delete", message);
    
    // Should NOT show the full menu while in confirmation mode
    ExpectFalse(strstr(message, "Exit Menu") != -1);
}
