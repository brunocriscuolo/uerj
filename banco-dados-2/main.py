# -*- coding: utf-8 -*-

import couchdb
from flask import Flask, render_template, request, redirect, flash
from wtforms import Form, StringField, IntegerField, SelectField, SubmitField

DEBUG = True
app = Flask(__name__)
app.config.from_object(__name__)
app.config['SECRET_KEY'] = '4a1264a4393116fb1ada9b128d8f0d22'


couchserver = couchdb.Server()
dbname = "person"
if dbname in couchserver:
    db = couchserver[dbname]
else:
    db = couchserver.create(dbname)


class RegisterForm(Form):
    nome = StringField('Nome')
    idade = IntegerField('Idade')
    matricula = IntegerField('Matricula')
    curso = StringField('Curso')
    disciplina = StringField('Disciplina de interesse')
    email = StringField('Email')


ITENS = [('nome','Nome'), ('idade','Idade'), ('matricula','Matricula'), ('curso','Curso'), ('disciplina','Disciplina de interesse'), ('email','Email')]
class SearchForm(Form):
    busca = StringField()
    filtro = SelectField(choices=ITENS)
    retorno_nome = []
    retorno_idade = []
    retorno_matricula = []
    retorno_curso = []
    retorno_disciplina = []
    retorno_email = []
    cont = 0
    display = False


@app.route("/", methods=['GET', 'POST'])
def inicio():
    return render_template('inicio.html')


@app.route("/cadastrar", methods=['GET', 'POST'])
def cadastrar():
    register_form = RegisterForm(request.form)

    if request.method == 'POST':
        nome = request.form['nome']
        idade = request.form['idade']
        matricula = request.form['matricula']
        curso = request.form['curso']
        disciplina = request.form['disciplina']
        email = request.form['email']

        db[matricula] = dict( 
                              nome = nome.lower(),
                              idade = idade.lower(),
                              matricula = matricula.lower(),
                              curso = curso.lower(),
                              disciplina = disciplina.lower(),
                              email = email.lower()
                            )

        flash('O cadastro de ' + nome + ' foi realizado com sucesso.')

    return render_template('cadastro.html', form=register_form)


@app.route("/buscar", methods=['GET', 'POST'])
def buscar():
    search_form = SearchForm(request.form)

    if request.method == 'POST':
        del search_form.retorno_nome[:]
        del search_form.retorno_idade[:]
        del search_form.retorno_matricula[:]
        del search_form.retorno_curso[:]
        del search_form.retorno_disciplina[:]
        del search_form.retorno_email[:]

        pesquisa = request.form['busca']
        pesquisa.lower()
        
        dictionary = dict(ITENS)
        filtro_ativo = dictionary.get(search_form.filtro.data)

        for key, value in dictionary.items():
            if value == filtro_ativo:
                flag = key

        mango = { 'selector': {flag : pesquisa}, 'fields': ['nome', 'idade', 'matricula', 'curso', 'disciplina', 'email']}

        for row in db.find(mango):
            search_form.retorno_nome.append(row['nome'])
            search_form.retorno_idade.append(row['idade'])
            search_form.retorno_matricula.append(row['matricula'])
            search_form.retorno_curso.append(row['curso'])
            search_form.retorno_disciplina.append(row['disciplina'])
            search_form.retorno_email.append(row['email'])
            search_form.cont = search_form.cont + 1

        search_form.display = True

        flash(' Dados encontrados e carregados com sucesso!')        

    return render_template('busca.html', form=search_form)


if __name__ == "__main__":
    app.run()