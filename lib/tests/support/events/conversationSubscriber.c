//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled;

/////////////////////////////////////////////////////////////////////////////
public int TimesConversationEventHappenedReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void conversationEventHappened(object caller, object initiator)
{
    NumTimesCalled++;
}
