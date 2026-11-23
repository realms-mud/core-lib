//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Queen Arueil inclines her "
        "head in greeting. @S@'Welcome. I hope the court has given "
        "you a fair hearing.'");
    addTopic("the royal family", "@S@'The king and I are proud "
        "of our children. Their duties take them in different "
        "directions, but they remain a family.'");
    addResponse("first conversation", "Do you attend every council?",
        "@D@She glances toward the gathered court.");
    addResponseTopic("first conversation", "Do you attend every "
        "council?", "the royal family");
}
