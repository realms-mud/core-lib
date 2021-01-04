//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/doors/baseDoor.c";

private int isRaised = 1;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("portcullis");

    addDescriptionTemplate("a raised portcullis");
    useExteriorLighting();
}

/////////////////////////////////////////////////////////////////////////////
public void lowerPortcullis(object initiator)
{
    isRaised = 0;
    addDescriptionTemplate("a closed portcullis");

    messageParser->displayMessage(
        sprintf("##InitiatorName## ##Infinitive::close## the "
            "%s.", elementName),
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void raisePortcullis(object initiator)
{
    isRaised = 1;
    addDescriptionTemplate("a raised portcullis");

    messageParser->displayMessage(
        sprintf("##InitiatorName## ##Infinitive::raise## the "
            "%s.", elementName),
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void PortcullisIsClosedByDefault()
{
    isRaised = 0;
    addDescriptionTemplate("a closed portcullis");
}

/////////////////////////////////////////////////////////////////////////////
public int isLocked()
{
    return !isRaised;
}

/////////////////////////////////////////////////////////////////////////////
public void displayLockedMessage(object initiator)
{
    messageParser->displayMessage(
        sprintf("##InitiatorName## ##Infinitive::try## to go through the "
            "%s, but it is closed.", elementName),
        initiator, 0, "description", "environment", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void displayCloseMessage(object initiator, object originalLocation)
{
}

/////////////////////////////////////////////////////////////////////////////
public void displayOpenMessage(object initiator)
{
}
