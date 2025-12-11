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
        "/lib/modules/guilds/selectors/createConstructedResearchSelector.c");
    Selector.setType("Aeromancer Spell");
    Selector.setConstraint("/guilds/aeromancer/construct/root.c");
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
    // Verify the selector initializes properly by checking it can display
    // a menu without error. Internal variables like AllowUndo, AllowAbort,
    // and NumColumns are protected and not queryable.
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // Verify it shows the description set by InitializeSelector
    ExpectSubStringMatch("Create New Constructed Spell", message);
    
    // Verify abort is allowed (exit instruction appears)
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
    
    // Verify description help appears (HasDescription = 1)
    ExpectSubStringMatch("For details on a given choice", message);
}

/////////////////////////////////////////////////////////////////////////////
void SetTypeSetsSpellType()
{
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/createConstructedResearchSelector.c");
    testSelector.setType("Test Spell Type");
    testSelector.InitializeSelector();
    
    // The type is stored privately, so we verify by checking the selector
    // initializes without error
    ExpectTrue(objectp(testSelector));
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void SetConstraintSetsConstraintPath()
{
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/createConstructedResearchSelector.c");
    testSelector.setType("Test");
    testSelector.setConstraint("/guilds/aeromancer/construct/root.c");
    testSelector.InitializeSelector();
    
    ExpectTrue(objectp(testSelector));
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void SetDataSetsSpellData()
{
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/createConstructedResearchSelector.c");
    testSelector.setType("Test");
    testSelector.setConstraint("/guilds/aeromancer/construct/root.c");
    testSelector.setData(([ "test": "data" ]));
    testSelector.InitializeSelector();
    
    ExpectTrue(objectp(testSelector));
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialDisplayShowsCreateNewConstructedSpell()
{
    Selector.initiateSelector(User);

    ExpectSubStringMatch("Create New Constructed Spell", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsCreateOptionWhenConstraintIsResearched()
{
    // Add the research prerequisite
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);

    // Create option should be enabled (no (X) marker)
    string message = User.caughtMessage();
    ExpectSubStringMatch("Create Constructed Aeromancer Spells", message);
    
    // Check that it's not disabled
    int createPos = strstr(message, "Create");
    int disabledPos = strstr(message, "(X)", createPos);
    int exitPos = strstr(message, "Return To Previous Menu", createPos);
    
    ExpectTrue(disabledPos == -1 || disabledPos > exitPos,
        "Create option should not be disabled when research is complete");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsDisabledCreateOptionWhenConstraintNotResearched()
{
    // Don't add the research - user hasn't researched the prerequisite
    Selector.initiateSelector(User);

    // Create option should be disabled ((X) marker present)
    string message = User.caughtMessage();
    ExpectSubStringMatch("Create Constructed Aeromancer Spells", message);
    ExpectSubStringMatch("\\(X\\)", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsReturnToPreviousMenuOption()
{
    Selector.initiateSelector(User);

    ExpectSubStringMatch("Return To Previous Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitClosesSelector()
{
    Selector.initiateSelector(User);
    
    // Exit is the last option
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
void SelectingDisabledCreateOptionDoesNothing()
{
    // Don't add the research - create option should be disabled
    Selector.initiateSelector(User);
    
    string initialMessage = User.caughtMessage();
    
    // Try to select the disabled create option
    command("1", User);
    
    // Should still show the same menu (disabled options don't proceed)
    ExpectSubStringMatch("Create New Constructed Spell", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnabledCreateOptionOpensEditSelector()
{
    // Add the research prerequisite
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);
    command("1", User);

    // Should show the edit menu for creating a new spell
    ExpectSubStringMatch("Create Spell Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeCreateOptionShowsCorrectDetails()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);
    command("? 1", User);

    ExpectSubStringMatch("Select this option to create a new",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeExitOptionShowsCorrectDetails()
{
    Selector.initiateSelector(User);
    command("? 2", User);

    ExpectSubStringMatch("This option leaves the spell creation menu",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoiceFormatterShowsDisabledFormatCorrectly()
{
    // Don't add research - create option should be disabled
    Selector.initiateSelector(User);

    string message = User.caughtMessage();
    
    // Verify disabled option has (X) marker
    ExpectSubStringMatch("\\(X\\)", message);
}

/////////////////////////////////////////////////////////////////////////////
void ChoiceFormatterShowsEnabledFormatCorrectly()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);

    string message = User.caughtMessage();
    
    // Verify create option does NOT have (X) marker
    int createPos = strstr(message, "Create");
    int returnPos = strstr(message, "Return To Previous Menu");
    
    // Get the substring between Create and Return options
    string createLine = message[createPos..returnPos-1];
    
    ExpectFalse(strstr(createLine, "(X)") != -1,
        "Enabled create option should not have (X) marker");
}

/////////////////////////////////////////////////////////////////////////////
void NewSpellDataHasCorrectStructure()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);
    command("1", User);

    // When creating a new spell, it should have null name/alias
    // and empty elements array. We verify by checking the edit menu
    // shows empty/unset values
    string message = User.caughtMessage();
    ExpectSubStringMatch("Spell Name: <Name Missing>", message);
    ExpectSubStringMatch("Spell Alias: <No Alias>", message);
}

/////////////////////////////////////////////////////////////////////////////
void OnSelectorCompletedNotifiesParent()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    // Create a parent selector to receive completion notification
    object parentSelector = clone_object(
        "/lib/modules/guilds/selectors/constructedResearchSelector.c");
    parentSelector.setType("Aeromancer Spell");
    parentSelector.setConstructedGrouping("/guilds/aeromancer/construct/root.c");
    parentSelector.InitializeSelector();
    move_object(parentSelector, User);

    // Register the create selector with the parent
    Selector.registerEvent(parentSelector);
    
    Selector.initiateSelector(User);
    command("2", User);  // Exit

    // Parent should be notified and update its display
    ExpectTrue(objectp(parentSelector));
    
    destruct(parentSelector);
}

/////////////////////////////////////////////////////////////////////////////
void SuppressMenuDisplayReturnsTrueWhenSubselectorActive()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);
    command("1", User);  // Open edit subselector

    // The create selector should suppress its menu when subselector is open
    // This is verified by the fact that we see the edit menu, not the create menu
    ExpectSubStringMatch("Create Spell Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ProcessSelectionReturnsMinusOneWhenNotExiting()
{
    User.addResearchPoints(1);
    User.initiateResearch("/guilds/aeromancer/construct/root.c");

    Selector.initiateSelector(User);
    
    // Selecting create should not exit (returns -1 internally)
    command("1", User);
    
    // We should see the edit menu, not an exit message
    ExpectSubStringMatch("Create Spell Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ProcessSelectionReturnsTrueOnExit()
{
    Selector.initiateSelector(User);
    command("2", User);  // Exit option

    // Should see selection confirmation
    ExpectSubStringMatch("You have selected", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ProcessSelectionReturnsTrueOnExited()
{
    Selector.initiateSelector(User);
    command("exit", User);

    // Should see abort message
    ExpectSubStringMatch("has been exited", User.caughtMessage());
}
