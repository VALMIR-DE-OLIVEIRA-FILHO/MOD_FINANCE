<?php

class Lancamento {

    public $id;
    public $descricao;
    public $valor;
    public $tipo;  // entrada | saida
    public $data;

    public function __construct($id, $descricao, $valor, $tipo, $data) {
        $this->id = $id;
        $this->descricao = $descricao;
        $this->valor = $valor;
        $this->tipo = $tipo;
        $this->data = $data;
    }

    public function toLine() {
        return "{$this->id}|{$this->descricao}|{$this->valor}|{$this->tipo}|{$this->data}";
    }

    public static function fromLine($line) {
        $p = explode("|", trim($line));
        return new Lancamento($p[0], $p[1], $p[2], $p[3], $p[4]);
    }
}
