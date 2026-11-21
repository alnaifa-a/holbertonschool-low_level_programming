#include "dog.h"

/**
 * copy_str - makes a copy of a string in newly allocated memory
 * @s: the string to copy
 *
 * Return: pointer to the copy, or NULL if s is NULL or malloc fails
 */
static char *copy_str(char *s)
{
	char *copy;
	unsigned int len, i;

	if (s == NULL)
		return (NULL);

	for (len = 0; s[len] != '\0'; len++)
		;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = s[i];

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the dog's owner
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	d->name = copy_str(name);
	d->owner = copy_str(owner);

	if ((name != NULL && d->name == NULL) ||
	    (owner != NULL && d->owner == NULL))
	{
		free(d->name);
		free(d->owner);
		free(d);
		return (NULL);
	}

	d->age = age;

	return (d);
}
