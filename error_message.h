/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:52:01 by imouhtad          #+#    #+#             */
/*   Updated: 2025/02/20 01:35:33 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_OPEN_FILE		"Incorrect MAP_FILE / Open File failed"
# define ERR_MAP_READING	"Reading error"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_ALLOC_FAILED 	"Memory allocation failed"

void	ft_error(char *str);

#endif