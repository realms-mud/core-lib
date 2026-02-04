//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

private int eventCallCount = 0;
private object lastCaller = 0;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Event Handler Test");
    addSpecification("type", "personality");
    addSpecification("root", "test event handler");
    addSpecification("event handlers", ({ "onTestEvent" }));
    addSpecification("cost", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void onTestEvent(object caller, mixed data)
{
    eventCallCount++;
    lastCaller = caller;
}

/////////////////////////////////////////////////////////////////////////////
public int eventWasCalled()
{
    return eventCallCount > 0;
}

/////////////////////////////////////////////////////////////////////////////
public int getEventCallCount()
{
    return eventCallCount;
}

/////////////////////////////////////////////////////////////////////////////
public object getLastCaller()
{
    return lastCaller;
}

/////////////////////////////////////////////////////////////////////////////
public void resetEventCount()
{
    eventCallCount = 0;
    lastCaller = 0;
}
