//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Father Osric looks up from "
        "his reading and offers a warm, if weary, smile. "
        "@S@'Welcome, child. Whether you seek solace or simply "
        "shelter from the road, you are welcome here.'");
    addResponse("first conversation", "What is this place?",
        "@S@'This is a humble chapel, dedicated to the light that "
        "guides us through darkness. I have tended it for nearly "
        "thirty years now.' @D@He gazes at the stained glass with "
        "evident affection. @S@'It is not grand, but it serves "
        "its purpose well enough.'");
    addResponseTopic("first conversation", "What is this place?",
        "the chapel");
    addResponse("first conversation", "I could use some guidance.",
        "@D@Osric nods slowly, his expression growing thoughtful. "
        "@S@'Then you have come to the right place. Sit, and tell "
        "me what weighs on your mind. I find that burdens shared "
        "are burdens halved.'");

    addTopic("the chapel", "@S@'I came here as a young man, full "
        "of certainty about the world.' @D@He chuckles softly. "
        "@S@'The years have a way of replacing certainty with "
        "questions, but I find the questions more honest.' @D@His "
        "expression turns more serious. @S@'Of late, I have felt "
        "a shadow growing. Something stirs in the east, in the "
        "old hills. The land itself seems uneasy.'");
    addResponse("the chapel", "A shadow?",
        "@D@Osric shakes his head slowly. @S@'I cannot name it. "
        "But I have lived long enough to know the difference "
        "between an old man's fancy and a genuine warning. The "
        "birds have changed their songs, and the well water "
        "tastes of iron where once it ran sweet.' @D@He meets "
        "your eyes steadily. @S@'Be watchful, traveler. "
        "Whatever comes, it will find us soon enough.'");
}
