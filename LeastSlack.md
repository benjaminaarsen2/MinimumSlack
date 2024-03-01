# Assignment example

### Eerste lijn

**2 3** betekent 
- 2 jobs 
- 3 machines

### Eerste job

**0 30 1 30 2 10**

**Machine 0, 1 en 2, daarop volgt de taakduur**

Dus: 

**Job 1**
- Taak 1: 
	- Machine 0
		- Tijdsduur 30
- Taak 2: 
	- Machine 1
		- Tijdsduur 30
- Taak 3: 
	- Machine 2
		- Tijdsduur 10
		
**Job 2**
- Taak 1:
	- Machine 0
		- Tijdsduur 60
- Taak 2:
	- Machine 1
		- Tijdsduur 15
- Taak 3:
	- Machine 2
		- Tijdsduur 10
		
		
### ES - Earliest start
Per taak wordt bijgehouden wanneer deze op zijn vroegst begonnen is.

De duration kan je berekenen door de de duration van de laatste taak bij zijn earliest start op te tellen.

Earliest start voor 

**Job 1**
- Taak 1
	- 0
- Taak 2
	- 30
- Taak 3
	- 60

Duration 70

**Job 2**
- Taak 1
	- 0
- Taak 2
	- 60
- Taak 3
	- 75

Duration 85


### Slack berekenen

job met de hoogste duration heeft 0 slack. De slack van de andere taken kan je berekeken door het verschil te berekenen tussen de job en de job met de hoogste duration.

Dus **Job 1** heeft 15 slack en **Job 2** heeft 0 slack.

### Plannen van taken

De job met het minste slack heeft voorrang. Je begint dus met inplannen bij **Job 2**

Je kan bij het programmeren per seconde kijken of je al een taak kan doen. Het kan ook **slimmer**:

- Kijk naar de earliest start van je taken zodat je weet wanneer je weer aan de slag kan.


#### De eerste taak is klaar, en nu?

Nu moeten alle (behalve van taken die je al gehad hebt) earliest start properties opnieuw berekend worden van de andere taken. Dus van **Job 1** wordt nu **Taak 1** een earliest start van 60 ipv 0, omdat we al een taak hiervoor uitgevoerd hebben. 

De reden dat we niet door gaan naar **taak 2** van **job 2** is omdat na de earliest starts en slack te berekenen, **Job 1** heeft nu minder slack, en krijgt dus voorrang.

We gaan dus verder met **Taak 1** van **Job 1**

Nu kunnen we ook **taak 2** van **job 2** inplannen want deze heeft nog steeds een earliest start van 60, we plannen dus op tijdstip t60 twee taken in.

### En verder?

Op enig moment kan het zijn dat je een hele job uitgevoerd hebt, deze kan je dan markeren zodat je je in de code alleen nog maar hoeft te focussen op andere jobs. Je kijkt dan wat is de kleinste earliest start op dit moment en dan ga je daar verder.

		