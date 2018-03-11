object critter;
#define TP this_player()
#define TN this_player()->query_name()

int search() {
  switch(random(9)) {
    case 1: return 
      printf("You search around for a while and get incredibly bored.\n"),1;
    case 2: return
      printf("You dejectedly search the ground, finding nothing.\n"),1;
    case 3:
      tell_room(environment(TP), sprintf("%s spots an ant peacefully "
        "crawling along doing ant things.\n%s screams, `LOOK!!! NATURE!'\n"
        "%s maliciously steps on it, laughing hysterically.\n", TN, TN,
        capitalize(TP->query_pronoun())));
      printf("You find nothing else of interest and sadly move along.\n");
      return 1;
    case 4:
      return printf("You spot a rather interesting clod of dirt.\n"
        "Sadly, as you go to pick it up, it breaks.\n"),1;
    case 5: return
      printf("You look around. You find nothing. You grumble and move on.\n"),1;
    case 6: return
      printf("You look around but find nothing to alter the monotony.\n"),1;
    case 7:
      return printf("You moan in despair as you find nothing of value.\n"),1;
    case 8:
      return printf("You stomp on several small shrubs but this doesn't help "
        "you find anything.\n"),1;
    default:
      if (!critter) {
        printf("You search for a while and discover that you are not alone.\n");
        critter = clone_object("/lib/tests/support/services/mockNPC.c");
        critter->generate(TP->query_level());
        move_object(critter, environment(this_player()));
        return 1;
      }
      printf("You find little but boredom and despair.\n");
      return 1;
  }
  return 1;
}
