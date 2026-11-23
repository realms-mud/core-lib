//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Jask draws a fresh length of "
        "twine through the mesh. @S@'This tear will hold now.'");
    addTopic("net repair", "@S@'A net is mended before it goes aboard. "
        "One weak place can spoil a whole morning's work.'");
    addResponse("first conversation", "How do you find the torn mesh?",
        "@D@He stretches the net against the light.");
    addResponseTopic("first conversation", "How do you find the torn mesh?",
        "net repair");
}
