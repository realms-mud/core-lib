//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "We start talking for the first time.");
    addResponse("first conversation", "OK...", "Then let's talk.");
    addTopic("default", "This is the default conversation");
    addResponse("default", "Quest...", "I wanna do a quest!");
    addResponse("default", "Goodbye", "See you later!");
    addResponse("default", "State Prerequisite", "block by state");
    addResponsePrerequisite("default", "State Prerequisite", (["state":(["type": "state", "state key":"/lib/tests/support/core/testStateMachine.c", "value": "met the king"])]));
    addResponse("default", "Opinion Prerequisite", "block by opinion");
    addResponsePrerequisite("default", "Opinion Prerequisite", (["opinion":(["type": "opinion", "value": 50])]));

    addTopic("start quest", "@D@A wispy figure appears. It is largely skeletal in "
        "nature, though ethereal and without substance. A "
        "bitterly frigid chill emanates from the thing. It is "
        "enveloped by a thin white veil, almost as of silk.\n"
        "\nIn a hoarse, raspy voice that seems "
        "almost to come out of a great depth, the figure "
        "speaks, @S@'Greetings, seekers. Welcome to your "
        "trial. That which you seek lies through the mists "
        "before you. Ere you may pass, you must satisfy my "
        "curiosity. You are unlike those who I am accustomed "
        "to... testing. Who are you and why are you here?'@D@ "
        "It folds its arms and gives a toothful leer that can "
        "only be interpreted as a smile.");
    addResponseTopic("default", "Quest...", "start quest");
    addResponse("start quest", "My name is...", "@S@'I am ##InitiatorName3rd## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy "
        "your curiousity. Am I allowed to ask of you then?'");
    addResponse("start quest", "None of your business", "@S@'Who I am is not your concern, wraith. You"
        " have a task for me? Get on with it.'");
    addResponse("start quest", "I am someone...", "@S@'I am one who wishes to complete this "
        "trial.'");
    addTopic("bye", "Not if I see you first.");
    addResponseTopic("default", "Goodbye", "bye");
    addTopic("block by state", "State not blocked topic");
    addTopic("block by opinion", "Opinion not blocked topic");

    addTopic("serve the king", "You are serving the king");
}
