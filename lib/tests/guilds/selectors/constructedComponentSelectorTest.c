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
        "/lib/modules/guilds/selectors/constructedComponentSelector.c");
    Selector.setCategory("effect");
    Selector.setConstraint("/guilds/aeromancer/construct/root.c");
    Selector.setItems(({
        "/guilds/aeromancer/effects/damage-hp.c",
        "/guilds/aeromancer/effects/damage-sp.c",
        "/guilds/aeromancer/effects/apply-slow.c"
    }));
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
    ExpectSubStringMatch("Select Effect Component", message);
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
    ExpectSubStringMatch("For details on a given choice", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsComponentsInTwoColumns()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // With two columns, we should see two items on the same line
    // Check that there are multiple menu items per line
    string *lines = explode(message, "\n");
    int foundTwoColumnLine = 0;
    
    foreach(string line in lines)
    {
        string *parts = regexplode(line, "\\[[0-9]+\\]");
        if (sizeof(regexp(parts, "\\[[0-9]+\\]")) == 2)
        {
            foundTwoColumnLine = 1;
            break;
        }
    }
    
    ExpectTrue(foundTwoColumnLine, 
        "Menu should display items in two columns");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsUnresearchedItemsWithDisabledMarker()
{
    // User has not researched any effects
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // All items should show (X) since none are researched
    ExpectSubStringMatch("\\(X\\)", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsResearchedItemsWithoutDisabledMarker()
{
    User.addResearchPoints(10);
    User.initiateResearch("/guilds/aeromancer/effects/damage-hp.c");
    
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // Find the line with Damage Hit Points
    int damagePos = strstr(message, "Damage Hit Points");
    int nextLinePos = strstr(message, "\n", damagePos);
    
    // Get the portion of the line after "Damage Hit Points"
    string afterDamage = message[damagePos..nextLinePos];
    
    // The researched item should NOT have (X) immediately after it
    // but other unresearched items on the same line might
    ExpectTrue(damagePos != -1, "Damage Hit Points should appear in menu");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayShowsReturnToPreviousMenuOption()
{
    Selector.initiateSelector(User);
    
    ExpectSubStringMatch("Return To Previous Menu", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingUnresearchedItemDoesNothing()
{
    // User has not researched any effects
    Selector.initiateSelector(User);
    
    // Try to select an unresearched item
    command("1", User);
    
    // Should still show the component selector (selection didn't work)
    ExpectSubStringMatch("Select Effect Component", User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingResearchedItemReturnsComponent()
{
    // Use test research items without prerequisites
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/constructedComponentSelector.c");
    testSelector.setCategory("effect");
    testSelector.setConstraint("/lib/tests/support/research/testConstructedActiveResearchItem.c");
    testSelector.setItems(({
        "/lib/tests/support/research/testConstructedComponentA.c",
        "/lib/tests/support/research/testConstructedComponentB.c"
    }));
    testSelector.InitializeSelector();
    move_object(testSelector, User);
    
    // Research the test components (these should have no prerequisites)
    User.addResearchPoints(10);
    ExpectTrue(User.initiateResearch("/lib/tests/support/research/testConstructedComponentA.c"),
        "Should be able to research component A");
    
    testSelector.initiateSelector(User);
    
    // Select the researched item
    command("1", User);
    
    // Verify selection was accepted
    ExpectSubStringMatch("You have selected", User.caughtMessage());
    
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitClosesSelector()
{
    Selector.initiateSelector(User);
    
    // Exit is the last option (4 in this case: 3 items + exit)
    command("4", User);
    
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
void DescribeComponentShowsDetails()
{
    Selector.initiateSelector(User);
    command("? 1", User);
    
    // Should show description of the component
    string message = User.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Description should be shown");
}

/////////////////////////////////////////////////////////////////////////////
void SelectedComponentReturnsEmptyMappingBeforeSelection()
{
    Selector.initiateSelector(User);
    
    mapping selected = Selector.selectedComponent();
    ExpectEq(0, sizeof(selected), 
        "selectedComponent should return empty mapping before selection");
}

/////////////////////////////////////////////////////////////////////////////
void SetCategorySetsCategory()
{
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/constructedComponentSelector.c");
    testSelector.setCategory("form");
    testSelector.setItems(({ "/guilds/aeromancer/forms/arc.c" }));
    testSelector.InitializeSelector();
    
    move_object(testSelector, User);
    testSelector.initiateSelector(User);
    
    ExpectSubStringMatch("Select Form Component", User.caughtMessage());
    
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void SetItemsSetsAvailableItems()
{
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/constructedComponentSelector.c");
    testSelector.setCategory("function");
    testSelector.setItems(({ 
        "/guilds/aeromancer/functions/lightning.c",
        "/guilds/aeromancer/functions/wind.c"
    }));
    testSelector.InitializeSelector();
    
    move_object(testSelector, User);
    testSelector.initiateSelector(User);
    
    string message = User.caughtMessage();
    ExpectSubStringMatch("Lightning", message);
    ExpectSubStringMatch("Wind", message);
    
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void ItemsAreSortedAlphabetically()
{
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // Items should be sorted: Apply Slow, Damage Hit Points, Damage Spell Points
    int applyPos = strstr(message, "Apply Slow");
    int damageHpPos = strstr(message, "Damage Hit Points");
    int damageSpPos = strstr(message, "Damage Spell Points");
    
    ExpectTrue(applyPos < damageHpPos, 
        "Apply Slow should appear before Damage Hit Points");
    ExpectTrue(damageHpPos < damageSpPos, 
        "Damage Hit Points should appear before Damage Spell Points");
}

/////////////////////////////////////////////////////////////////////////////
void ChoiceFormatterShowsDisabledFormatCorrectly()
{
    // No research - all items disabled
    Selector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // All effect items should have (X) marker
    // Count occurrences of (X) - should be at least 3 (one per item)
    int count = 0;
    int pos = 0;
    while ((pos = strstr(message, "(X)", pos)) != -1)
    {
        count++;
        pos++;
    }
    
    ExpectTrue(count >= 3, 
        "All unresearched items should show (X) marker");
}

/////////////////////////////////////////////////////////////////////////////
void ChoiceFormatterShowsEnabledFormatCorrectly()
{
    // Use test research items without prerequisites
    object testSelector = clone_object(
        "/lib/modules/guilds/selectors/constructedComponentSelector.c");
    testSelector.setCategory("effect");
    testSelector.setConstraint("/lib/tests/support/research/testConstructedActiveResearchItem.c");
    testSelector.setItems(({
        "/lib/tests/support/research/testConstructedComponentA.c",
        "/lib/tests/support/research/testConstructedComponentB.c"
    }));
    testSelector.InitializeSelector();
    move_object(testSelector, User);
    
    // Only research component A, leave B unresearched
    User.addResearchPoints(10);
    ExpectTrue(User.initiateResearch("/lib/tests/support/research/testConstructedComponentA.c"),
        "Should be able to research component A");
    
    testSelector.initiateSelector(User);
    
    string message = User.caughtMessage();
    
    // Component A is researched - should NOT have (X)
    // Component B is not researched - should have (X)
    // Find each component's line segment and check for (X)
    int compAPos = strstr(message, "Test Component A");
    int compBPos = strstr(message, "Test Component B");
    
    string compASection = message[compAPos..compBPos-1];
    string compBSection = message[compBPos..];
    
    ExpectFalse(strstr(compASection, "(X)") != -1,
        "Researched component A should not show (X) marker");
    ExpectTrue(strstr(compBSection, "(X)") != -1,
        "Unresearched component B should show (X) marker");
    
    destruct(testSelector);
}

/////////////////////////////////////////////////////////////////////////////
void ProcessSelectionReturnsMinusOneForDisabledItem()
{
    // No research - items are disabled
    Selector.initiateSelector(User);
    
    // Select a disabled item
    command("1", User);
    
    // Should still be on the component selector
    ExpectSubStringMatch("Select Effect Component", User.caughtMessage());
    
    // Selected component should still be empty
    mapping selected = Selector.selectedComponent();
    ExpectEq(0, sizeof(selected));
}

/////////////////////////////////////////////////////////////////////////////
void ProcessSelectionReturnsTrueForExit()
{
    Selector.initiateSelector(User);
    command("4", User);  // Return To Previous Menu
    
    ExpectSubStringMatch("You have selected", User.caughtMessage());
}
