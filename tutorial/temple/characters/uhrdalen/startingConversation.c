//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void thePlayerAndTheirName()
{
    addTopic("first conversation", "@D@A wispy figure appears. It is largely "
        "skeletal in nature, though ethereal and without substance. A bitterly "
        "frigid chill emanates from the thing. It is enveloped by a thin white "
        "veil, almost as of silk.\n\nThe figure looks at ##InitiatorName## as "
        "it speaks in a hoarse, raspy voice that seems almost to come out of "
        "a great depth, @S@'Greetings, seeker. Welcome to your trial. That "
        "which you seek lies through the mists before you. Ere you may pass, "
        "you must satisfy my curiosity. You are unlike those who I am "
        "accustomed to... testing. Who are you and why are you here?'@D@ It "
        "folds its arms and gives a toothsome leer that can only be "
        "interpreted as a smile.");

    addResponse("first conversation", "My name is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'I am ##ActorName## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy your curiousity. "
        "Am I allowed to ask of you then?'");

    addResponse("first conversation", "None of your business...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@'Who I "
        "am is not your concern, wraith. You have a task for me? Get on with "
        "it.'");

    addResponse("first conversation", "I think I'll deflect...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, @S@'I am "
        "one who wishes to complete this trial.'");

    addTopic("wrong answer", "@D@The figure laughs - a harsh, gravelly sound "
        "that sets your nerves on edge. @S@'It would be most unfortunate were "
        "you to have come all this way to get not what you seek. I am your "
        "only route to this goal and so you must humor me. I shall leave you "
        "to reflect on your awful interpersonal skills if you do choose not "
        "to answer my very civil and reasonable inquiry. Again, who are you "
        "and why are you here?'");
    addResponseTopic("first conversation", "None of your business...", 
        "wrong answer");
    addResponseTopic("first conversation", "I think I'll deflect...",
        "wrong answer");

    addResponse("wrong answer", "My name is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'I am ##ActorName## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy your curiousity. "
        "Am I allowed to ask of you then?'");

    addResponse("wrong answer", "I think not...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'You may not have my name.' @D@The "
        "wispy figure shrugs and vanishes.");

    addResponse("wrong answer", "Leave...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::turn## away. The wispy figure shrugs and vanishes.");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    thePlayerAndTheirName();

    addTopic("who are you", "@D@The figure shrugs, @S@'You may ask, but be "
        "prepared to be ignored until I am satisfied... To my question "
        "regarding who you are, you gave me your name. That is simply what "
        "others call you. Do not tell me that you define yourself by a label "
        "given unto you by others. Given that same logic, it would be best to "
        "not respond next with your title. As for why you are here, you are "
        "very clever... We would not be having this conversation if you were "
        "not here for the trial. What is your motivation for wanting to pass the trial?'");
 
    addResponseTopic("first conversation", "My name is...", "who are you");
    addResponseTopic("wrong answer", "My name is...", "who are you");
    addResponse("who are you", "Fine. I'll spill my guts...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'Very well. I do not wish to speak in "
        "riddles. I am one of the Chosen of The Lord of Waters and by the "
        "good grace, blessing and gifts of the aforementioned, I am here on "
        "a mission to restore balance to this world.' @D@@C@##InitiatorName## "
        "##ResponseInfinitive::gesture## in the direction one might suppose the Heart "
        "of Obedience artifact would lie. @S@'That thing is in my way. I have "
        "answered you, now who might you be?'");
    addResponse("who are you", "I will offer up a little...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'Very well. I do not wish to speak in "
        "riddles. I am here on a mission to restore balance to this world.' "
        "@D@@C@##InitiatorName## ##ResponseInfinitive::gesture## in the direction one "
        "might suppose the Heart of Obedience artifact would lie. @S@'That thing is "
        "in my way. I have answered you, now who might you be?'");

    addTopic("who might you be", "@S@'Who might I be? That is a tale in and "
        "of itself - a tale that deviates considerably from the topic at hand. "
        "I am weak. I am strong. Burning. Freezing. Hiding behind "
        "inconsequential armor. I am my greatest fear. I am accursed, damned. "
        "I was beloved, but now forgotten. I am a thrall to the desires of "
        "others. Most importantly, I may well be an example to all of what "
        "not to do as you go through your life. ' @D@The being chuckles at this.");
    addResponseTopic("who are you", "Fine. I'll spill my guts...", "who might you be");
    addResponseTopic("who are you", "I will offer up a little...", "who might you be");

    addResponse("who might you be", "@I@Say nothing@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::make## no response.");

    addTopic("who might you be PT2", "@D@After a short yet uncomfortable pause, "
        "the being continues. @S@'That can be a mouthful. You may call me "
        "Uhrdalen. As to your answer, you still do not understand the question. "
        "Too often, you spoke of external entities: Lord of Water this and "
        "Chosen that. You are of varied kin, some inconsequential and some "
        "not. You were chosen by a God and you speak of your mission. You "
        "judge your worth by the company you keep and not by what is within "
        "you. I did not ask you of any but yourself. Be that as it may, I do "
        "not believe you know and I shan't press.'");
    addResponseTopic("who might you be", "@I@Say nothing@E@", "who might you be PT2");

}
