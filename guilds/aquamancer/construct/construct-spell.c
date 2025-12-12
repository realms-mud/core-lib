//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/activeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Construct Aquamancer Spell");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of constructing spells that can provide "
        "complex effects.");

    addSpecification("scope", "self");
    addSpecification("research type", "granted");
    addSpecification("command template", "construct aquamancer spell");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    object selectorObj = clone_object(
        "/lib/modules/guilds/selectors/constructedResearchSelector.c");

    selectorObj.setType("Aquamancer Spell");
    selectorObj.setConstructedGrouping("/guilds/aquamancer/construct/root.c");

    move_object(selectorObj, owner);
    selectorObj.registerEvent(this_object());
    selectorObj.initiateSelector(owner);

    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}
