//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
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
    addResponse("start quest", "My name is...", "@S@'I am ##InitiatorName3rd## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy "
        "your curiousity. Am I allowed to ask of you then?'");
    addResponse("start quest", "None of your business", "@S@'Who I am is not your concern, wraith. You"
        " have a task for me? Get on with it.'");
    addResponse("start quest", "I am someone...", "@S@'I am one who wishes to complete this "
        "trial.'");

}
