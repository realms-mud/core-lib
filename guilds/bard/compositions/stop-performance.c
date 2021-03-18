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
        addSpecification("name", "Stop Performance");
        addSpecification("source", "bard");
        addSpecification("description", "This skill allows a bard to prematurely "
            "end a performance that's in progress.");

        addSpecification("scope", "self");
        addSpecification("research type", "granted");
        addSpecification("command template", "stop performance");
        addSpecification("use ability message", "##InitiatorName## "
            "##Infinitive::stop## performing ##InitiatorPossessive## song.");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    if (owner->hasActiveCompositeResearch())
    {
        mapping activeResearch = owner->getActiveCompositeResearch();
        ret = owner->deactivateCompositeResearch(
            activeResearch["constraint"],
            activeResearch["name"]);

        if (ret)
        {
            displayMessage(specificationData, "use ability message",
                owner, owner);
        }
    }
    else
    {
        displayMessageToSelf("You are not currently performing any songs.", 
            owner);
    }
    return ret;
}
