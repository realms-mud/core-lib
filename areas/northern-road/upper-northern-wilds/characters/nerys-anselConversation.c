//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nerys glances at your boots "
        "before she looks at your face. @S@'If you are headed north, "
        "the road is passable. That is not the same as saying it is "
        "safe. Tell me what you are carrying and I can tell you "
        "what the climb will cost.'");
    addTopic("the watch", "@S@'I take the high turn before dawn. "
        "You learn the road by hearing it first: a loose stone, "
        "a wagon brake, a wolf moving through brush. The eyes catch "
        "up after the ears.'");
    addTopic("the ridge", "@D@She points toward the dark line of "
        "pines. @S@'There is a narrow shelf behind the mill. It "
        "saves a little distance, but the wind takes your words "
        "and the coach track is easy to miss. Do not follow a "
        "fresh print off the gravel without checking who made it.'");
    addTopic("the drill yard", "@S@'The target faces the slope "
        "because the wind changes there. A recruit who learns to "
        "hold a bow in still air has learned only half the work.'");
    addTopic("the red patch", "@D@Nerys taps the strip sewn over "
        "her boot. @S@'My first winter here. The old sole split "
        "on a night patrol, and a fisherwoman gave me sailcloth "
        "to mend it. I have had better boots since. I keep this "
        "one where I can see it.'");
    addTopic("the outlaws", "@S@'The warning boards are there for "
        "a reason. Some people use the hill paths to avoid the "
        "toll, others to avoid being seen. Do not assume every "
        "stranger in a dark coat is the same sort of trouble.'");

    addResponse("first conversation", "Where does the ridge path go?",
        "@D@Nerys traces the route on the map with one finger. "
        "@S@'It rejoins the road beyond the mill. There is a "
        "wrecked coach on the shelf; keep your hands off the "
        "driver's box until you know who else is watching.'");
    addResponseTopic("first conversation",
        "Where does the ridge path go?", "the ridge");
    addResponse("the watch", "What do you listen for?",
        "@D@She turns her head toward the wind beyond the palisade. "
        "@S@'A cart that slows without a reason. A stream that "
        "gets louder after rain. A bell that rings once and then "
        "not again. The road rarely gives only one warning.'");
    addResponse("first conversation", "Can I practice in the yard?",
        "@D@Nerys points to the leaning target post. "
        "@S@'Ask before you use the targets. The left one has a "
        "split post; if you loose into it, the head can glance "
        "back at you.'");
    addResponseTopic("first conversation",
        "Can I practice in the yard?", "the drill yard");
    addResponse("the drill yard", "Why does the target face the slope?",
        "@D@She raises a hand as a gust cuts across the yard. "
        "@S@'The gusts turn where the ground falls away. I want "
        "the recruits to notice it before they loose.'");
    addResponse("first conversation", "Who repaired your boot?",
        "@D@Nerys taps the red patch sewn over her boot. "
        "@S@'Sairen at the shore. She was younger than I was and "
        "already better with a needle than the quartermaster.'");
    addResponseTopic("first conversation", "Who repaired your boot?",
        "the red patch");
    addResponse("first conversation", "Are the outlaws dangerous?",
        "@D@She watches the road as she answers. "
        "@S@'Some are hungry, some are cruel, and some are both. "
        "The sign tells you to stay alert. It does not tell you "
        "to stop thinking.'");
    addResponseTopic("first conversation",
        "Are the outlaws dangerous?", "the outlaws");
    addResponse("the ridge", "Is there a safer route around the coach?",
        "@D@Nerys traces the longer route along the road. "
        "@S@'Stay on the main road. The shelf is shorter, not safer. "
        "The way back down is steep once the light goes.'");
    addResponse("the outlaws", "Would you arrest someone for stealing food?",
        "@D@She folds her arms and meets your gaze. "
        "@S@'I would ask who went hungry and who was paid. Then I "
        "would look at what was taken. A uniform does not excuse "
        "lazy judgment.'");
}
