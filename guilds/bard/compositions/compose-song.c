//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/activeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        activeResearchItem::reset(arg);
        addSpecification("name", "Compose Song");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of composing songs that can provide "
            "complex effects.");

        addSpecification("scope", "self");
        addSpecification("research type", "granted");
        addSpecification("command template", "compose song");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    object selectorObj =
        clone_object("/guilds/bard/selectors/songsSelector.c");
    move_object(selectorObj, owner);
    selectorObj->registerEvent(this_object());
    selectorObj->initiateSelector(owner);

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
